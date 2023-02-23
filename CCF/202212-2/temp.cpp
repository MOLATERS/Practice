#include <iostream>
using namespace std;
struct Mission{
    struct Mission* next;
    int pre;
    int time;
    Mission(struct Mission* a,int c,int d):next(a),pre(c),time(d){}
};
struct Mission* M[100]; 
int StartTime(int n){
    if(n==0)return 0;
    return StartTime(M[n]->pre)+M[n]->time;
}
int main(){
    int head[100]={0};
    int day;
    int mission;
    int count=0;
    scanf("%d %d",&day,&mission);
    for(int i=1;i<=mission;i++){
        short x;
        cin>>x;
        M[i]=new Mission(nullptr,x,0);
        if(x!=0) M[x]->next=M[i];
        else
        head[count++]=i;
    }
    for(int i=1;i<=mission;i++){
        cin>>M[i]->time;
    }
    for(int i=1;i<=mission;i++){
        cout<<day+1-StartTime(M[i])<<" ";
    }
}
