#include<bits/stdc++.h>
using namespace std;
void subsets(int arr[],int n){
    if(n==0){
        cout<<"{}";
        return;
    }
    subsets(arr,n-1);
    for(int i=0;i<n;i++)
        cout<<"{ "<<arr[i]<<" }";
    cout<<"{ ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<" }";
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    subsets(arr,n);
}