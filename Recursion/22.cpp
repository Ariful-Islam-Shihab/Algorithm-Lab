#include<bits/stdc++.h>
using namespace std;
int numOfDigits(int i){
    if(i==0)
        return 0;
    return 1+numOfDigits(i/10);
}
int main(){
    int n;
    cin>>n;
    cout<<numOfDigits(n)<<endl;
    return 0;
}