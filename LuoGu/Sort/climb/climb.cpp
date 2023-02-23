#include <iostream>
#include <cmath>
// #include <vector>
#define _for(i,a,b) for(int i=a;i<b;i++)
using namespace std;
struct point{
    float x,y,z;
}P[200000];
class Solution{
public:
    void Summarize(int n){
        double sum=0;
        _for(i,0,n-1)
            sum=sum+Distance(P[i],P[i+1]);
        printf("%.3lf",sum);
    }
    float Distance(struct point a,struct point b){
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
    }
    void quicksort(int left,int right){
        if(left<right){
            int i=left;
            int j=right;
            int mid=(left+right)/2;
            swap(P[left],P[mid]);
            struct point x=P[left];
            while(i<j){
                while(i<j&&P[j].z>=x.z){
                    j--;
                }
                if(i<j){
                    P[i++]=P[j];
                }
                while(i<j&&P[i].z<x.z){
                    i++;
                }
                if(i<j){
                    P[j--]=P[i];
                }
            }
            P[i]=x;
            quicksort(left,i-1);
            quicksort(i+1,right);
        }
    }
    void swap(struct point &a,struct point&b){
        struct point temp;
        temp=a;
        a=b;
        b=temp;
    }
};

int main(){
    int n;
    scanf("%d",&n);
    _for(i,0,n){
        scanf("%lf%lf%lf",&P[i].x,&P[i].y,&P[i].z);
    }
    Solution V;
    V.quicksort(0,n);
    V.Summarize(n);
}