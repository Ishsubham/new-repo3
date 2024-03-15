#include<iostream>
using namespace std;
void swap(int &a , int &b){
    int temp = a;
    a = b ;
    b = temp;
}
int main(){
    int n ;
    cin>>n;
    int a[n];
    for(int i =0;i<n; i++){
        cin>>a[i];
    }
    int low = 0,high = n-1;
    while(low<high){
        if(a[low]<0)
        low++;
        else if(a[high]>0)
        high--;
        else
        swap(a[low],a[high]);
    }
    for(int i =0;i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}