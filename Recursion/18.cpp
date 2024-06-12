#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}
int countPrime(int arr[][5],int n){
    if(n==0)
        return 0;
    int count=0;
    for(int j=0;j<5;j++){
        if(isPrime(arr[n-1][j]))
            count++;
    }
    return count+countPrime(arr,n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n][5];
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++)
            cin>>arr[i][j];
    }
    cout<<countPrime(arr,n)<<endl;
    return 0;
}