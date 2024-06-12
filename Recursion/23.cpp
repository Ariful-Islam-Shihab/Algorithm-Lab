#include<bits/stdc++.h>
using namespace std;
int sumOfDigits(int i){
    if(i==0)
        return 0;
    return (i%10)+sumOfDigits(i/10);
}
int main(){
    int n;
    cin>>n;
    cout<<sumOfDigits(n)<<endl;
    return 0;
}