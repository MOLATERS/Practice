#include<cstdio>
#include<cmath>
#include<algorithm>
#define _for(i,a,b) for(int i=a;i<b;i++)
struct Node{
    double x,y,z;
    bool operator<(const Node &other)const{
        return z<other.z;
    }
}P[500050];
class Solution{
public:
    void Summarize(int n){
        double sum=0;
        _for(i,0,n-1)
            sum=sum+sqrt((P[i].x-P[i+1].x)*(P[i].x-P[i+1].x)
            +(P[i].y-P[i+1].y)*(P[i].y-P[i+1].y)
            +(P[i].z-P[i+1].z)*(P[i].z-P[i+1].z));
        printf("%.3lf",sum);
    }
};
int main(){
    int n;
    scanf("%d",&n);
    _for(i,0,n){
        scanf("%lf%lf%lf",&P[i].x,&P[i].y,&P[i].z);
    }
    std::sort(P,P+n);
    Solution v;
    v.Summarize(n);
}