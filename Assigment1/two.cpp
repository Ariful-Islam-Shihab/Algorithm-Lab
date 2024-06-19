#include<bits/stdc++.h>
using namespace std;
int series(int i){
    if(i==0)
        return 0;
    else {
        int x=((i*3)-2)*pow(2,i);
        return x+series(i-1);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<series(n)<<endl;
    return 0;
}