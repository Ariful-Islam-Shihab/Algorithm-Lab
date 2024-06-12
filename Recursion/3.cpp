#include<bits/stdc++.h>
using namespace std;
int fib(int i){
    if(i==0||i==1)
        return i;
    return fib(i-1)+fib(i-2);
}
int main(){
    int x;
    cin>>x;
    cout<<fib(x);
    return 0;
}