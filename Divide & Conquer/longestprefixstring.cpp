#include<bits/stdc++.h>
using namespace std;
string prefix(string words[],int left,int right){
    if(left==right)
        return words[left];
    int mid=(left+right)/2;
    string leftside=prefix(words,left,mid);
    string rightside=prefix(words,mid+1,right);
    int i=0;
    string x="";
    while(leftside[i]==rightside[i]){
        x+=leftside[i];
        i++;
    }
    return x;
}
int main(){
    int n;
    cin>>n;
    string words[n];
    for(int i=0;i<n;i++)
        cin>>words[i];
    cout<<prefix(words,0,n-1)<<endl;
}