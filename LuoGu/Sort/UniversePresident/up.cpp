#include <iostream>
using namespace std;
struct vote{
    string num;
    int index;
};
vote* Vote[21]={nullptr};
void AdjustHeap(vote* Vote[21],int k,int n){
    Vote[0]=Vote[k];
    for(int i=2*k;i<=n;i*=2){
        if(i<n&&Vote[i]->num.compare(Vote[i+1]->num)){
            i++;
        }
        if(Vote[k]->num.compare(Vote[i]->num))break;
        else{
            Vote[k]=Vote[i];
            k=i;
        }
    }
    Vote[k]=Vote[0];
}
bool issmaller(string a,string b){
    int asize=a.size();
    int bsize=b.size();
    if(asize>bsize)return false;
    else if(asize<bsize)return true;
    else{
        int i=0;
        while(i<asize){
            if(a[i]>b[i])return false;
            if(a[i]<b[i])return true;
            i++;
        }
    }
    return false;
}
void Heap(vote** Vote,int n){
    for(int i=n/2;i>0;i--){
        AdjustHeap(Vote,i,n);
    }
}
int main(){
    int n;
    cin>>n;
    vote* Vote[21]={nullptr};
    for(int i=1;i<=n;i++){
        cin>>Vote[i]->num;
        Vote[i]->index=i;
    }
    Heap(Vote,n);
    cout<<Vote[1]->index<<endl<<Vote[1]->num;
}