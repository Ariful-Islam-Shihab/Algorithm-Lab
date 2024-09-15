#include<bits/stdc++.h>
using namespace std;
void sort(vector<int>&coins){
    for(int i=0;i<coins.size();i++){
        for(int j=i+1;j<coins.size();j++){
            if(coins[i]<coins[j])
                swap(coins[i],coins[j]);
        }
    }
}
int main(){
    int amount;
    int N;
    cin>>amount>>N;
    vector<int>coins;
    for(int i=0;i<N;i++){
        int t;
        cin>>t;
        coins.push_back(t);
    }
    sort(coins);
    int sum=0;
    for(int x:coins){
        int temp=amount/x;
        if(temp==0)
            continue;
        cout<<"Coin-> "<<x<<" quantity-> "<<temp<<endl;
        amount=amount%x;
        sum+=temp;
    }
    cout<<"Total coins: "<<sum<<endl;
}