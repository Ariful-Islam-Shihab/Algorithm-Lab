#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        string code;
        char c;
        int freq;
        TreeNode*left,*right;
        TreeNode(char c,int freq){
            this->c=c;
            left=NULL;
            right=NULL;
            code="";
            this->freq=freq;
        }
};
class op{
    public:
        bool operator()(TreeNode* a,TreeNode* b){
            return a->freq>b->freq;
        }
};
int main(){
    priority_queue<TreeNode*,vector<TreeNode*>,op>myQ;
    int n;
    cin>>n;
    TreeNode*root=NULL;
    while(n--){
        char c;
        int freq;
        cin>>c>>freq;
        myQ.push(new TreeNode(c,freq));
    }
    while(!myQ.empty()){
        TreeNode*left=myQ.top();
        myQ.pop();
        if(myQ.empty()){
            root=left;
            break;
        }
        TreeNode*right=myQ.top();
        myQ.pop();
        root=new TreeNode('$',left->freq+right->freq);
        root->left=left;
        root->right=right;
        myQ.push(root);
    }
    queue<TreeNode*>trev;
    trev.push(root);
    while(!trev.empty()){
        root=trev.front();
        trev.pop();
        if(root->left){
            TreeNode*left=root->left;
            left->code+=root->code+"0";
            if(left->c!='$'){
                cout<<left->c<<"->"<<left->code<<endl;
            }else{
                trev.push(left);
            }
        }
        if(root->right){
            TreeNode*right=root->right;
            right->code+=root->code+"1";
            if(right->c!='$'){
                cout<<right->c<<"->"<<right->code<<endl;
            }else{
                trev.push(right);
            }
        }

    }
    return 0;
}