#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n],sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int diff;
    cin>>diff;
    sum=(sum+diff)/2;
    int DP[n+1][sum+1];
    for(int i=1;i<=sum;i++)
        DP[0][i]=0;
    DP[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(arr[i-1]<=j){
                DP[i][j]=DP[i-1][j-arr[i-1]]+DP[i-1][j];
            }else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }
    cout<<DP[n][sum]<<endl;
    return 0;
}