#include <iostream>
#include <algorithm>
#define _for(i,a,b) for(int i=a;i<b;i++)
using namespace std;
struct stu{
    string name;
    int year,month,day;
    bool operator<(const stu &others)const{
        if(year!=others.year)return year<others.year;
        if(month!=others.month)return month<others.month;
        if(day!=others.day)return day<others.day;
        return false;
        }
    }T[20000];
int main(){
    int n;
    scanf("%d",&n);
    _for(i,0,n){cin>>T[i].name;scanf("%d %d %d\n",&T[i].year,&T[i].month,&T[i].day);}
    std::stable_sort(T,T+n);
    _for(i,0,n){cout<<T[i].name<<endl;}
    return 0;
}