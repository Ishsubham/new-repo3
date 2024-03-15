// find number of spanning trees in a graph 
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double determinant(vector<vector<double> >& mat, int n) {
    double det = 1;
    int sign = 1;
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(mat[j][i]) > abs(mat[k][i])) {
                k = j;
            }
        }
        if (k != i) {
            for (int j = 0; j < n; ++j){
                swap(mat[i][j], mat[k][j]);
            }
            sign *= -1;
        }
        if (mat[i][i] == 0){
            return 0;
        }
        for (int j = i + 1; j < n; ++j) {
            double factor = mat[j][i] / mat[i][i];
            for (int k = i; k < n; ++k) {
                mat[j][k] -= factor * mat[i][k];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        det *= mat[i][i];
    }
    return det * sign;
}
int countSpanningTrees(vector<vector<int> >& graph, int V) {
    vector<vector<double> > laplacian(V, vector<double>(V, 0));
    for (int i = 0; i < V; ++i) {
        int degree = 0;
        for (int j = 0; j < V; ++j) {
            if (graph[i][j]) {
                laplacian[i][j] = -1;
                degree++;
            }
        }
        laplacian[i][i] = degree;
    }
    vector<vector<double> > cofactor(V - 1, vector<double>(V - 1, 0));
    for (int i = 1; i < V; ++i) {
        for (int j = 1; j < V; ++j) {
            cofactor[i - 1][j - 1] = laplacian[i][j];
        }
    }
    return static_cast<int>(determinant(cofactor, V - 1));
}
int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int> > graph(V, vector<int>(V, 0));

    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    int spanning_trees = countSpanningTrees(graph, V);
    cout << "Number of Spanning Trees: " << spanning_trees << endl;
 return 0;
}