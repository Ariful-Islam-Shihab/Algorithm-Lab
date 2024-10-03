#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int vertex;
        long long int cost,stamina;
        Node(int vertex,long long int cost,long long int stamina){
            this->cost=cost;
            this->vertex=vertex;
            this->stamina=stamina;
        }
};
class cmp{
    public:
        bool operator()(Node a,Node b){
            if(a.cost==b.cost)
                return a.stamina<b.stamina;
            return a.cost>b.cost;
        }
};
class edge{
    public:
        int v;
        long long int w;
        edge(int v,long long int w){
            this->v=v;
            this->w=w;
        }
};
int main(){
    int V,E,I,U;
    cin>>V>>E>>I>>U;
    vector<edge>adjList[V+1];
    while(E--){
        int u,v;
        long long int w;
        cin>>u>>v>>w;
        adjList[u].push_back(edge(v,w));
        adjList[v].push_back(edge(u,w));
    }
    long long int sleep[V+1],stamina[V+1];
    for(int i=1;i<=V;i++){
        cin>>stamina[i]>>sleep[i];
    }
    bool vis[V+1];
    long long int cost[V+1];
    int parent[V+1];
    for(int i=1;i<=V;i++){
        cost[i]=LLONG_MAX;
        vis[i]=false;
        parent[i]=-1;
    }
    priority_queue<Node,vector<Node>,cmp>myQ;
    myQ.push(Node(I,0,0));
    cost[I]=0;
    while(!myQ.empty()){
        auto current=myQ.top();
        myQ.pop();
                if (vis[current.vertex]) continue;

        vis[current.vertex]=true;
        if(vis[U])
            break;
        for(auto child:adjList[current.vertex]){
            if(!vis[child.v]){
                if(child.w>current.stamina){
                    if(stamina[current.vertex]>=child.w){
                        if(cost[child.v]>current.cost+sleep[current.vertex]){
                            cost[child.v]=current.cost+sleep[current.vertex];
                            parent[child.v]=current.vertex;
                            myQ.push(Node(child.v,cost[child.v],stamina[current.vertex]-child.w));
                        }
                    }
                }else{
                    parent[child.v]=current.vertex;
                    cost[child.v]=current.cost;
                    myQ.push(Node(child.v,current.cost,stamina[current.vertex]-child.w));
                }
            }
        }
    }
    if(!vis[U])
        cout<<"-1"<<endl;
    else{
        cout<<cost[U]<<endl;
    }
    return 0;
}