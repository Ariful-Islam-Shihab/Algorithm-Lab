#include<bits/stdc++.h>
using namespace std;
string numberTostring(int x){
    stack<char>myS;
    string s="";
    while(x!=0){
        myS.push((x%10)+'0');
        x=x/10;
    }
    while(!myS.empty()){
        s+=myS.top();
        myS.pop();
    }
    return s;
}
int main(){
    int distance,milage,n;
    cin>>distance>>milage>>n;
    vector<int>stops;
    while(n--){
        int t;
        cin>>t;
        stops.push_back(t);
    }
    string ans="";
    int fuelleft=milage,covered=0;
    for(int i=0;i<stops.size()-1;i++){
        if(i==0){
            fuelleft-=stops[i];
            covered+=stops[i];
        }
        else{
            fuelleft-=(stops[i]-stops[i-1]);
            covered+=(stops[i]-stops[i-1]);
        }
        if(fuelleft<(stops[i+1]-stops[i])){
            ans+="stop at gas "+numberTostring(i+1)+" ( "+numberTostring(stops[i])+" miles )\n";
            fuelleft=milage;
        }
        cout<<fuelleft<<endl;
    }
    if(covered+fuelleft>=distance)
        cout<<ans<<endl;
    else
        cout<<"Can't reach destination"<<endl;
    return 0;
}