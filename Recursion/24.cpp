#include<bits/stdc++.h>
using namespace std;
int reverse(int n,int i=0){
    if(n==0)
        return i;
    i=i*10+(n%10);
    return reverse(n/10,i);
}
int main(){
    int n;
    cin>>n;
    if(reverse(n)==n)
        cout<<"Palindrome"<<endl;
    else
        cout<<"Not Palindrome"<<endl;
    return 0;
}