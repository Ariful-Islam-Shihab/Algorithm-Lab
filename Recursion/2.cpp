#include<bits/stdc++.h>
using namespace std;
int pow(int x,int i){
    if(i==0)
        return 1;
    return x*pow(x,i-1);
}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<pow(x,y);
    return 0;
}