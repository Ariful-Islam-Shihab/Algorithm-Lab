#include<bits/stdc++.h>
using namespace std;
int minimum(int arr[],int n){
    if(n==0)
        return INT_MAX;
    return min(arr[n-1],minimum(arr,n-1));
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<minimum(arr,n)<<endl;
    return 0;
}