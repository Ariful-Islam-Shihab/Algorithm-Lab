#include<bits/stdc++.h>
using namespace std;
bool DP[1000][1000];
void printer(int n,int target,int arr[]){
    if(n==0||target==0)
        return;
    if(DP[n][target]==DP[n-1][target])
        printer(n-1,target,arr);
    else{
        printer(n-1,target-arr[n],arr);
        cout<<arr[n]<<" "<<endl;
    }
}
int main(){

    int n;
    cin>>n;
    int arr[n+1]={0};
    arr[0]=0;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    int target;
    cin>>target;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(j==0)
                DP[i][j]=1;
            else if(i==0)
                DP[i][j]=0;

        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(arr[i]<=j){
                DP[i][j]=DP[i-1][j]||DP[i-1][j-arr[i]];
            }else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }
    printer(n,target,arr);
    cout<<DP[n][target]<<endl;
}