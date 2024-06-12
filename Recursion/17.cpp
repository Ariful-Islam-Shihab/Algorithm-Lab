#include<bits/stdc++.h>
using namespace std;
int maximum(int arr[][5],int n,int m){
    if(n==0)
        return INT_MIN;
    int x=INT_MIN;
    for(int j=0;j<m;j++)
        x=max(x,arr[n-1][j]);
    return max(x,maximum(arr,n-1,m));
}
int main(){
    int n,m;
    cin>>n;
    int arr[n][5];
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++)
            cin>>arr[i][j];
    }
    cout<<maximum(arr,n,5);
}