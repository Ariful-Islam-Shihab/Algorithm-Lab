#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int price[n+1]={0};
    for(int i=1;i<n;i++){
        cin>>price[i];
    }
    int length;
    cin>>length;
    int DP[length+1],cut[length+1];
    DP[0]=0;
    cut[0]=0;
    for(int i=1;i<=length;i++){
        DP[i]=INT_MIN;
        cut[i]=0;
        for(int j=1;j<=n;j++){
            if(i>=j){
                if(DP[i-j]+price[j]>DP[i]){
                    DP[i]=max(DP[i],DP[i-j]+price[j]);
                    cut[i]=j;
                }
            }
        }
    }
    cout<<DP[length]<<endl;
    int i=length;
    while(cut[i]!=0){
        cout<<cut[i]<<" ";
        i-=cut[i];
    }
}