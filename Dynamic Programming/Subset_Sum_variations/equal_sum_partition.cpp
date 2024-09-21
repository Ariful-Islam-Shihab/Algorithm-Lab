#include<bits/stdc++.h>
using namespace std;
int DP[1005][1005];
void printer(int i,int j,int arr[]){
    if(i<=0||j<0)
        return;
    if(DP[i][j]!=DP[i-1][j]){
        cout<<arr[i-1]<<" ";
        printer(i-1,j-arr[i-1],arr);
    }
    else{
        printer(i-1,j,arr);
    }

}
int main(){
    int n;
    cin>>n;
    int arr[n],sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%2!=0){
        cout<<"INVALID"<<endl;
        return 0;
    }
    sum=sum/2;
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
    printer(n,sum,arr);
    return 0;
}