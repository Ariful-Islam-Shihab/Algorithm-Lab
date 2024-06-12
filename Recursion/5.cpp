#include<bits/stdc++.h>
using namespace std;
void printevens(int a,int b){
    if(a>b)
        return;
    if(a%2==0)
        cout<<a<<" ";
    printevens(a+1,b);
} 
int main(){
    int a,b;
    cin>>a>>b;
    printevens(a,b);
    return 0;
}
int a(){
    return 10;
}
