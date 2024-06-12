#include<bits/stdc++.h>
using namespace std;
void printEven(int arr[],int n){
    if(n==0)
        return;
    if(arr[n-1]%2==0)
        cout<<arr[n-1]<<" ";
    printEven(arr,n-1);
}
void printOdd(int arr[],int n){
    if(n==0)
        return;
    if(arr[n-1]%2!=0)
        cout<<arr[n-1]<<" ";
    printOdd(arr,n-1);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    printEven(arr,n);
    printOdd(arr,n);
    return 0;
}