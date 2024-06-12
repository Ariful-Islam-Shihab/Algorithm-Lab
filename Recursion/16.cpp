#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}
int countPrime(int arr[],int n){
    if(n==0)
        return 0;
    if(isPrime(arr[n-1]))
        return 1+countPrime(arr,n-1);
    return countPrime(arr,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<countPrime(arr,n)<<endl;
    return 0;
}