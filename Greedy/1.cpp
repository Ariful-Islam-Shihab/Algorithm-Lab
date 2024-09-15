#include<bits/stdc++.h>
using namespace std;
class item{
    public:
        float val,weight;
        float vPerW;
        item(float val,float weight){
            this->val=val;
            this->weight=weight;
            vPerW=(float)val/weight;
        }
};
void printer(vector<item>&items){
    float profit=0;
    for(int i=0;i<items.size();i++){
        cout<<i+1<<". Value-> "<<items[i].val<<"tk Weigth-> "<<items[i].weight<<"kg ValuePerWeight-> "<<items[i].vPerW<<endl;
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
void knapsack(vector<item>items,int weight){
    vector<item>taken;
    int i=0;
    while(weight>0 && i<items.size()){
        if(weight>=items[i].weight){
            float w=items[i].weight;
            float val=items[i].val;
            weight-=w;
            taken.push_back(item(val,w));
        }else{
            float w=weight;
            float val=items[i].vPerW*w;
            weight-=w;
            taken.push_back(item(val,w));
        }
        i++;
    }
    cout<<"Taken Items"<<endl;
    printer(taken);
    
}
int main(){
    int n;
    cin>>n;
    vector<item>items;
    for(int i=0;i<n;i++){
        float val,weight;
        cin>>weight>>val;
        items.push_back(item(val,weight));
    }
    printer(items);
    sorting(items);
    printer(items);
    int weight;
    cin>>weight;
    knapsack(items,weight);
}