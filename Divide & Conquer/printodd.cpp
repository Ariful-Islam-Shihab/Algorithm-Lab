#include<bits/stdc++.h>
using namespace std;
void printOdd(int arr[],int left,int right){
    if(left==right){
        if(arr[left]%2!=0)
            cout<<arr[left]<<" ";

        return;
    }
    int mid=(left+right)/2;
    printOdd(arr,left,mid);
    printOdd(arr,mid+1,right);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    printOdd(arr,0,n-1);
}