#include<bits/stdc++.h>
using namespace std;
int naturalSeries(int i){
    if(i==1)
        return 1;
    return i+naturalSeries(i-1);
}
int squareNaturalSeries(int i){
    if(i==1)
        return 1;
    return i*i+naturalSeries(i-1);
}
int series3(int i){
    if(i==1)
        return 3;
    return i*(i*2+1)+series3(i-1);
}
int series4(int i){
    if(i==1)
        return 6;
    return pow(2,i)*(i*2+1)+series3(i-1);
}
int series5(int i){
    if(i==1)
        return 24;
    return pow(2,i)*(i*2+1)*(5-i)+series3(i-1);
}
int main(){
    int n;
    cin>>n;
    cout<<"Series 1: "<<naturalSeries(n)<<endl;
    cout<<"Series 2: "<<squareNaturalSeries(n)<<endl;
    cout<<"Series 3: "<<series3(n)<<endl;
    cout<<"Series 4: "<<series4(n)<<endl;
    cout<<"Series 5: "<<series5(n)<<endl;
}