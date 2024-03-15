#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    for(int i=0;i<b.size();i++){
        a.push_back(b[i]);
    }
    cout<<endl<<a<<endl;
    return 0;
}