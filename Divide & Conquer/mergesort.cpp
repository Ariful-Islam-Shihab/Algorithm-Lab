#include<bits/stdc++.h>
using namespace std;
void mergesort(int arr[],int left,int right){
    if(left>=right)
        return;
    int mid=(left+right)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    vector<int>leftarr;
    vector<int>rightarr;
    for(int i=left;i<=mid;i++)
        leftarr.push_back(arr[i]);
    leftarr.push_back(INT_MAX);
    for(int i=mid+1;i<=right;i++)
        rightarr.push_back(arr[i]);
    rightarr.push_back(INT_MAX);
    int j=0,k=0;
    for(int i=left;i<=right;i++){
        if(leftarr[j]<rightarr[k]){
            arr[i]=leftarr[j];
            j++;
        }else{
            arr[i]=rightarr[k];
            k++;
        }
    }
}
void printer(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    printer(arr,n);
    mergesort(arr,0,n-1);
    printer(arr,n);
}