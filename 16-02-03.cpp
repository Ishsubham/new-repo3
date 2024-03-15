//find radius and diameter of a graph 
#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
int graph[MAX][MAX];
int V;

void initializeGraph(int vertices) {
    V = vertices;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            graph[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}

void addEdge(int u, int v, int weight) {
    graph[u][v] = weight;
    graph[v][u] = weight;
}
 
void floydWarshall(){
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX &&
                    graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int findEccentricity(int vertex) {
    int eccentricity = 0;

    for (int i = 0; i < V; ++i) {
        if (graph[vertex][i] != INT_MAX && graph[vertex][i] > eccentricity) {
            eccentricity = graph[vertex][i];
        }
    }

    return eccentricity;
}

int findDiameter() {
    int diameter = 0;

    for (int i = 0; i < V; ++i) {
        int eccentricity = findEccentricity(i);
        if (eccentricity > diameter) {
            diameter = eccentricity;
        }
    }

    return diameter;
}

int findRadius() {
    int radius = INT_MAX;
    for (int i = 0; i < V; ++i) {
        int eccentricity = findEccentricity(i);
        if (eccentricity < radius) {
            radius = eccentricity;
        }
    }
    return radius;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    initializeGraph(vertices);

    cout << "Enter edges (u, v, weight):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        addEdge(u, v, weight);
    }

    floydWarshall();

    cout << "Distance matrix:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> eccentricity;
    for (int i = 0; i < V; ++i) {
        int maxi = 0;
        for (int j = 0; j < V; ++j) {
            maxi = max(maxi,graph[i][j]);
        }
        eccentricity.push_back(maxi);
    }
    for(int i=0;i<eccentricity.size();i++){
        cout<<"the eccentricity of vertex "<<i<<" is "<<eccentricity[i]<<endl;
    }
    cout << "Diameter of the graph: " << findDiameter() << endl;
    cout << "Radius of the graph: " << findRadius() << endl;
    return 0;
}