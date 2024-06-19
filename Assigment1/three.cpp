#include<bits/stdc++.h>
using namespace std;
int binary(int x){
    if(x==0)
        return 0;
    return binary(x/2)*10+(x%2);
}
int reverse(int num,int rev){
    if(num==0)
        return rev;
    rev=rev*10+(num%10);
    return reverse(num/10,rev);
}
bool palindrome(int num){
    int bin=binary(num);
    int rev=reverse(bin,0);
    return bin==rev;
}
int main(){
    int x;
    cin>>x;
    if(palindrome(x))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}