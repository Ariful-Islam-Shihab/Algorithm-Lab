#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int amount;
    cin>>amount;
    int quantity[amount+1],ncoins[amount+1],coins[n];
    quantity[0]=0;
    ncoins[0]=0;
    for(int i=0;i<n;i++)
        cin>>coins[i];
    for(int i=1;i<amount+1;i++){
        quantity[i]=INT_MAX;
        ncoins[i]=0;
        for(int x:coins){
            if(i>=x){
                if(quantity[i]>quantity[i-x]+1){
                    quantity[i]=min(quantity[i],quantity[i-x]+1);
                    ncoins[i]=x;
                }
            }
        }
    }
    cout<<quantity[amount]<<endl;
    int i=amount;
    while(ncoins[i]!=0){
        cout<<ncoins[i]<<" ";
        i-=ncoins[i];
    }
}