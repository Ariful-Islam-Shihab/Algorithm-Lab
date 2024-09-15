#include<bits/stdc++.h>
using namespace std;
int DP[1000][1000];
void printer(int n,int w,int weight[],int price[]){
    if(n==0||w==0)
        return;
    if(DP[n][w]==DP[n-1][w])
        printer(n-1,w,weight,price);
    else{
        printer(n-1,w-weight[n],weight,price);
        cout<<"ITEM "<<n<<": "<<weight[n]<<" kg "<<price[n]<<" tk"<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    int weight[n+1]={0},value[n+1]={0};
    weight[0]=0;
    value[0]=0;
    for(int i=1;i<=n;i++)
        cin>>weight[i]>>value[i];
    int w;
    cin>>w;
    // int DP[n+1][w+1];
    for(int i=0;i<=n;i++){
        // cout<<weight[i]<<" "<<value[i]<<endl;
        for(int j=0;j<=w;j++){
            if(i==0||j==0)
                DP[i][j]=0;
            // cout<<DP[i][j]<<" ";
        }
        // cout<<endl;
    }
    // memset(DP,0,sizeof(DP));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(weight[i]<=j){
                DP[i][j]=max(DP[i-1][j],DP[i-1][j-weight[i]]+value[i]);
            }else{
                DP[i][j]=DP[i-1][j];
            }
        }
    }
    printer(n,w,weight,value);
    cout<<DP[n][w]<<endl;
}