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
    int diff=INT_MAX;
    for(int i=0;i<=sum;i++){
        if(DP[n][i]>0){
            int s1=i;
            int s2=sum-s1;
            diff=min(diff,abs(s1-s2));
        }
    }
    cout<<diff<<endl;
    return 0;
}