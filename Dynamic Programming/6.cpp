#include<bits/stdc++.h>
using namespace std;
int DP[100][100];
int lcs(string text1,string text2,int i,int j){
    if(i<0||j<0)
        return 0;
    if(DP[i][j]!=-1){
        return DP[i][j];
    }
    if(text1[i]==text2[j]){
        return DP[i][j]=lcs(text1,text2,i-1,j-1)+1;
    }
    return DP[i][j]=max(lcs(text1,text2,i-1,j),lcs(text1,text2,i,j-1));
}
void printer(string text1,string text2,int i,int j){
    if(i<0||j<0)
        return;
    if(DP[i][j]>DP[i-1][j]&&DP[i][j]>DP[i][j-1]){
        printer(text1,text2,i-1,j-1);
        cout<<text1[i];
    }else if(DP[i][j]==DP[i][j-1]){
        printer(text1,text2,i,j-1);
    }else{
        printer(text1,text2,i-1,j);
    }
}
int main(){
    memset(DP,-1,sizeof(DP));
    string text1,text2;
    cin>>text1>>text2;
    cout<<lcs(text1,text2,text1.length()-1,text2.length()-1)<<endl;
    printer(text1,text2,text1.length()-1,text2.length()-1);
}