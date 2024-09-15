#include<bits/stdc++.h>
using namespace std;
float sum=0;
class Question{
    public:
        float marks;
        float time,percentage,markspertime;
        int questionno;
        Question(float marks,float time,int questionno){
            this->marks=marks;
            this->time=time;
            this->markspertime=marks/time;
            this->questionno=questionno;
            this->percentage=100;
        }
};
void printer(vector<Question>&items){
    for(int i=0;i<items.size();i++){
        cout<<items[i].questionno<<".Time-> "<<items[i].time<<" Marks-> "<<items[i].marks<<" Ratio-> "<<items[i].markspertime<<endl;
    }
}
void sorting(vector<Question>&items){
    for(int i=0;i<items.size();i++){
        for(int j=i+1;j<items.size();j++){
            if(items[i].markspertime<items[j].markspertime)
                swap(items[i],items[j]);
        }
    }
}
void answered(vector<Question>&myQ){
    for(auto x:myQ){
        cout<<"Ques "<<x.questionno<<" "<<x.percentage<<"% -- "<<x.marks<<" marks\n";
    }
}
void knapsack(vector<Question>&myQ,float time){
    vector<Question>done;
    int i=0;
    while(time>0 && i<myQ.size()){
        if(time>=myQ[i].time){
            time-=myQ[i].time;
            float marks=myQ[i].marks;
            sum+=marks;
            int questionno=myQ[i].questionno;
            Question newQ=Question(marks,myQ[i].time,questionno);
            newQ.percentage=myQ[i].percentage;
            myQ.erase(myQ.begin()+i);
            done.push_back(newQ);
        }else{
            float per=(time/myQ[i].time)*100;
            float marks=time*myQ[i].markspertime;
            sum+=marks;
            Question newQ=Question(marks,myQ[i].time,myQ[i].questionno);
            myQ[i].percentage-=per;
            newQ.percentage=per;
            myQ[i].marks-=marks;
            myQ[i].time-=time;
            time=0;
            done.push_back(newQ);
        }
    }
    cout<<sum<<endl;
    answered(done);
}
int main(){
    int totalmarks,totaltime,N;
    cin>>totalmarks>>totaltime>>N;
    vector<Question>myQ;
    for(int i=0;i<N;i++){
        float marks,time;
        cin>>marks>>time;
        myQ.push_back(Question(marks,time,i+1));
    }
    // cout<<"\t<-------------Before Sorting------------------>"<<endl;
    // printer(myQ);
    sorting(myQ);
    // cout<<"\t<-------------After Sorting------------------>"<<endl;
    // printer(myQ);
    knapsack(myQ,totaltime);
    knapsack(myQ,totaltime);
}