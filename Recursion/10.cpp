#include<bits/stdc++.h>
using namespace std;
int maximum(int arr[],int n){
    if(n==0)
        return INT_MIN;
    return max(arr[n-1],maximum(arr,n-1));
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<maximum(arr,n)<<endl;
    return 0;
}