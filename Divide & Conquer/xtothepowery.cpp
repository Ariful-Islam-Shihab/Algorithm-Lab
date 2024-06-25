#include<bits/stdc++.h>
using namespace std;
int powerFinder(int base,int power){
    if(power==1)
        return base;
    if(power%2!=0){
        int mid=power/2;
        return powerFinder(base,mid)*powerFinder(base,mid+1);
    }
    int x=powerFinder(base,power/2);
    return x*x;
}
int main(){
    int base,power;
    cin>>base>>power;
    cout<<powerFinder(base,power);
    return 0;
}