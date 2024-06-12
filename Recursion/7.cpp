#include<bits/stdc++.h>
using namespace std;
void printer(int arr[],int n,int i=0){
    if(i==n)
        return;
    printer(arr,n,i+1);
    cout<<arr[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    printer(arr,n);
    return 0;
}