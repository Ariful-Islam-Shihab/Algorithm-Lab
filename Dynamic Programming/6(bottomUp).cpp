#include<bits/stdc++.h>
using namespace std;
int DP[100][100];
int lcs(string text1,string text2){
    for(int i=0;i<=text1.length();i++){
        for(int j=0;j<=text2.length();j++){
            if(i==0||j==0)
                DP[i][j]=0;
        }
    }

    for(int i=1;i<=text1.length();i++){
        for(int j=1;j<=text2.length();j++){
            if(text1[i-1]==text2[j-1]){
                DP[i][j]=DP[i-1][j-1]+1;
            }else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    return DP[text1.length()][text2.length()];
}
void printer(string text1,string text2,int i,int j){
    stack<char>myS;
    while(i>0&&j>0){
        if(DP[i][j]>DP[i-1][j]&&DP[i][j]>DP[i][j-1]){
            myS.push(text1[i-1]);
            i--;
            j--;
        }else if(DP[i][j]==DP[i-1][j]){
            i--;
        }else{
            j--;
        }
    }
    while(!myS.empty()){
        cout<<myS.top();
        myS.pop();
    }
    return;
}
int main(){
    memset(DP,-1,sizeof(DP));
    string text1,text2;
    cin>>text1>>text2;
    cout<<lcs(text1,text2)<<endl;
    printer(text1,text2,text1.length(),text2.length());
}