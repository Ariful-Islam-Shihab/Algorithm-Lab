#include<bits/stdc++.h>
using namespace std;
pair<int,int> maximumminimum(int arr[],int left,int right){
    if(left==right){
        return {arr[left],arr[left]};
    }
    int mid=(left+right)/2;
    auto lefts=maximumminimum(arr,left,mid);
    auto rights=maximumminimum(arr,mid+1,right);
    return {max(lefts.first,rights.first),min(lefts.second,rights.second)};
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    auto minmax=maximumminimum(arr,0,n-1);
    cout<<minmax.first<<" "<<minmax.second<<endl;
    return 0;
}