#include<bits/stdc++.h>
using namespace std;
class item{
    public:
        string name;
        float val,weight;
        float vPerW;
        item(string name,float val,float weight){
            this->name=name;
            this->val=val;
            this->weight=weight;
            vPerW=(float)val/weight;
        }
};
void printer(vector<item>&items){
    float profit=0;
    for(int i=0;i<items.size();i++){
        cout<<items[i].name<<": Value-> "<<items[i].val<<"tk Weigth-> "<<items[i].weight<<"kg ValuePerWeight-> "<<items[i].vPerW<<endl;
        profit+=items[i].val;
    }
    cout<<"Total Profit-> "<<profit<<endl;
}
void sorting(vector<item>&items){
    for(int i=0;i<items.size();i++){
        for(int j=i+1;j<items.size();j++){
            if(items[i].vPerW<items[j].vPerW)
                swap(items[i],items[j]);
        }
    }
}
void knapsack(vector<item>&items,float weight){
    vector<item>taken;
    int i=0;
    while(weight>0 && i<items.size()){
        if(weight>=items[i].weight){
            float w=items[i].weight;
            float val=items[i].val;
            weight-=w;
            taken.push_back(item(items[i].name,val,w));
            items.erase(items.begin()+i);
            continue;
        }else{
            float w=weight;
            float val=items[i].vPerW*w;
            weight-=w;
            taken.push_back(item(items[i].name,val,w));
            items[i].val-=val;
            items[i].weight-=w;
        }
        i++;
    }
    printer(taken);
    
}
int main(){
    int n;
    cin>>n;
    vector<item>items;
    for(int i=0;i<n;i++){
        float val,weight;
        string name;
        cin>>name>>val>>weight;
        items.push_back(item(name,val,weight));
    }
    printer(items);
    sorting(items);
    printer(items);
    int k;
    cin>>k;
    float weight;
    for(int i=0;!items.empty();i++){
        cin>>weight;
        cout<<"Theif "<<i+1<<": "<<endl;
        knapsack(items,weight);
    }
}