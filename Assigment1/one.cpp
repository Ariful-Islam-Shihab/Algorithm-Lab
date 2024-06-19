#include<bits/stdc++.h>
using namespace std;
void reverse(string s,int i){
    if(i==s.length())
        return;
    reverse(s,i+1);
    cout<<s[i];
    return;
}
int main(){
    string s;
    cin>>s;
    reverse(s,0);
    return 0;
}