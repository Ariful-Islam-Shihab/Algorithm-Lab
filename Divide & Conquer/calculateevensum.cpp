#include<bits/stdc++.h>
using namespace std;
int sum(int arr[],int left,int right){
    if(left==right){
        if(arr[left]%2==0)
            return arr[left];
        return 0;
    }
    int mid=(left+right)/2;
    return sum(arr,left,mid)+sum(arr,mid+1,right);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<sum(arr,0,n-1);
}