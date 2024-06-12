#include<bits/stdc++.h>
using namespace std;
bool palindrome(string s,int i){
    if(i>=s.length()/2)
        return true;
    if(s[i]!=s[s.length()-i-1])
        return false;
    return true && palindrome(s,i+1);
}
int main(){
    string s,final="";
    getline(cin,s);
    for(char x:s){
        if(x==' ')
            continue;
        final+=tolower(x);
    }
    if(palindrome(final,0))
        cout<<"True";
    else
        cout<<"False";
    return 0;
}