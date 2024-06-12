#include<bits/stdc++.h>
using namespace std;
int fact(int i){
    if(i==0||i==1)
        return 1;
    return i*fact(i-1);
}
int main(){
    int x,y;
    cin>>x;
    cout<<fact(x);
    return 0;
}