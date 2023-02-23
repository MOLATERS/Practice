#include <iostream>
using namespace std;
struct Mission{
    int next;
    int pre;
    int time;
    Mission(int a,int c,int d):next(a),pre(c),time(d){}
};
struct Mission* M[100]; 
int StartTime(int n){
    if(n==0)return 1;
    return StartTime(M[n]->pre)+M[n]->time;
}
int EndTime(int day,int n){
    if(M[n]->next==0)return day+1-M[n]->time;
    return EndTime(day,M[n]->next)-M[n]->time;
}
int main(){
    int day;
    int temp;
    int mission;
    int count=0;
    bool second=true;
    scanf("%d %d",&day,&mission);
    for(int i=1;i<=mission;i++){
        short x;
        cin>>x;
        M[i]=new Mission(0,x,0);
        if(x!=0) M[x]->next=i;
    }
    for(int i=1;i<=mission;i++){
        cin>>M[i]->time;
    }
    for(int i=1;i<=mission;i++){
        int j=StartTime(M[i]->pre);
        cout<<j<<" ";
        if(j+M[i]->time>day+1)
        second=false;
    }
    if(second){
        cout<<endl;
        for(int i=1;i<=mission;i++){
            cout<<EndTime(day,i)<<" ";
        }
    }
}
