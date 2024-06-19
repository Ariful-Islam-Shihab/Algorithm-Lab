#include<bits/stdc++.h>
using namespace std;
void helper(string s,int i,int j);
void permutations(string s,int i=0);
int main(){
    string s;
    cin>>s;
    permutations(s);
}
void helper(string s,int i,int j){
    if(j>=s.length())
        return;
    swap(s[i],s[j]);
    permutations(s,i+1);
    swap(s[i],s[j]);
    helper(s,i,j+1);
}
void permutations(string s,int i){
    if(i>=s.length()-1){
        cout<<s<<endl;
        return;
    }
    helper(s,i,i);
}