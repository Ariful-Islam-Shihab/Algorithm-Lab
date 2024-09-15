#include<bits/stdc++.h>
using namespace std;
class actvity{
    public:
        char club;
        int start,end;
        actvity(char club,int start,int duration){
            this->club=club;
            this->start=start;
            this->end=start+duration;
        }
};
void sort(vector<actvity>&clubs){
    for(int i=0;i<clubs.size();i++){
        for(int j=i+1;j<clubs.size();j++){
            if(clubs[i].end>clubs[j].end)
                swap(clubs[i],clubs[j]);
        }
    }
}
int main(){
    int N;
    cin>>N;
    vector<actvity>clubs;
    while(N--){
        char club;
        int start,duration;
        cin>>club>>start>>duration;
        clubs.push_back(actvity(club,start,duration));
    }
    sort(clubs);
    int x;
    cin>>x;
    vector<actvity>taken;
    taken.push_back(clubs[0]);
    int currentEnd=clubs[0].end+x;
    for(int i=1;i<clubs.size();i++){
        if(clubs[i].start>=currentEnd){
            taken.push_back(clubs[i]);
            currentEnd=clubs[i].end+x;
        }
    }
    for(auto x:taken){
        cout<<x.club<<endl;
    }
}