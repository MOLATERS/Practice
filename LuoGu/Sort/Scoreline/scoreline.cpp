#include <iostream>
using namespace std;
typedef struct{
    long index;
    int score;
}Vol;
Vol v[200]={{0,0}};
class Heap{
public:
    void buildmaxheap(int n){
        for(int i=n/2;i>0;i--){//只需要调整后面一半
            Adjustheap(i,n);
        }
    }
    void Adjustheap(int k,int n){
        v[0]=v[k];
        for(int i=2*k;i<=n;i*=2){
            if(i<n&&issmaller(v[i],v[i+1])){
                i++;
            }
            if(!issmaller(v[0],v[i]))break;
            else{
                v[k]=v[i];
                k=i;
            }
        }
        v[k]=v[0];
    }
    bool issmaller(Vol a,Vol b){
        if(a.score>b.score)return false;
        else if(a.score==b.score){
            if(a.index<=b.index)return false;
            else return true;
        }
        else 
        return true;
    }
    void swap(Vol &a,Vol &b){
        Vol c;
        c=a;
        a=b;
        b=c;
    }
    void heapsort(int n,int count){
        Vol answer[100]={{0,0}};
        buildmaxheap(n);
        int t=count;
        for(int i=n;i>0;i--){
            swap(v[1],v[i]);
            Adjustheap(1,i-1);
        }
        // for(int i=1;i<=n;i++){
        //     cout<<v[i].index<<" "<<v[i].score<<endl;
        // }
        int standard=v[n-count+1].score;
        while(count<n&&v[n-t+1].score==v[n-count].score){
            count++;
        }
        // cout<<v[n-count].score<<" "<<t<<endl;
        printf("%d %d\n",v[n-t+1].score,count);
        for(int i=n;i>n-count;i--){
            // cout<<answer[i].index<<" "<<answer[i].score<<endl;
            printf("%d %d\n",v[i].index,v[i].score);
        }
    }
};
class Solution{
public:
    void gradeline(int n,int m){
        int count=m*3/2;
        Heap s;
        s.heapsort(n,count);
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        // cin>>v[i].index>>v[i].score;
        scanf("%d %d",&v[i].index,&v[i].score);
    }
    Solution s;
    s.gradeline(n,m);
}