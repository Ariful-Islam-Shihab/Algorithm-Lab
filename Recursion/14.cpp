#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}
void printPrime(int arr[],int n){
    if(n==0)
        return;
    if(isPrime(arr[n-1]))
        cout<<arr[n-1]<<" ";
    printPrime(arr,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    printPrime(arr,n);
    return 0;
}