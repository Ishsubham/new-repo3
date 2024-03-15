//eulerian cycle 
#include<iostream>
#include<vector>
using namespace std;

int eulerian(vector<vector<int> > &adjmatrix,int vertex){
    int odd = 0,even = 0;
    for(int i=0;i<vertex;i++){
        int sum = 0;
        for(int j=0;j<vertex;j++){
            sum += adjmatrix[i][j];
        }
        if(sum%2 == 0)
        even++;
        else
        odd++;
    }
    if(even == vertex)
    return 2;
    else if(odd == 2)
    return 1;
    else 
    return 0;
}

int main(){
    cout<<"Enter the number of vertex : ";
    int v;
    cin>>v;
    vector<vector<int> > adjmatrix(v,vector<int>(v));
    cout<<"enter the adjacency matrix : "<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>adjmatrix[i][j];
        }
    }
    int ans = eulerian(adjmatrix,v);
    if(ans == 2)
    cout<<"the graph has eulerian cycle";
    else if(ans == 1)
    cout<<"the graph has eulerian path but not cycle";
    else if(ans == 0)
    cout<<"the graph has not eulerian path";
    return 0;
}