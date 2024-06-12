#include<bits/stdc++.h>
using namespace std;
int countEven(int arr[],int n){
    if(n==0)
        return 0;
    if(arr[n-1]%2==0)
        return 1+countEven(arr,n-1);
    countEven(arr,n-1);
}
int countOdd(int arr[],int n){
    if(n==0)
        return 0;
    if(arr[n-1]%2!=0)
        return 1+countOdd(arr,n-1);
    return countOdd(arr,n-1);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<countEven(arr,n)<<endl;
    cout<<countOdd(arr,n)<<endl;
    return 0;
}