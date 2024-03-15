// wap to find the number edges and number of vertex of a hypercube , determine the adjacent vertices 
// of the given hyper cube which will differ exctly by one bit 

#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the dimention of hypercube:";
    cin>>n;
    int total=pow(2,n);
    cout<<"Number of vertices of hypercube = "<<total<<endl;
    cout<<"Total no of edges of hypercube = "<<n*total/2<<endl;

    int vertex;
    cout<<"Enter the vertex for which you want to find the adjecent vertex : ";
    cin>>vertex;

    vector<int>x;
    int m=vertex;
    for(int i=0;i<n;i++){
        x.push_back(m%2);
        m/=2;
    }
    for(int i=x.size()-1;i>=0;i--){
        cout<<x[i];
    }
    cout<<endl;
    cout<<"The vertex which are adjecent to given vertex : "<<vertex<<" are \n";
    for(int i=0;i<x.size();i++){
        int new_vertex=vertex;
        if(x[i]==0) new_vertex+=pow(2,i);
        else new_vertex-=pow(2,i);
        cout<<new_vertex<<" ";
    }
    return 0;
}

