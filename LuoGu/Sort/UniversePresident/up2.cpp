#include <iostream>
using namespace std;
typedef struct Vote{
    string num;
    int index;
    Vote(string x,int y):num(x),index(y){};
}vote;
vote* people[21]={nullptr};
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
void AdjustHeap(int k,int n){
    people[0]=people[k];
    for(int i=2*k;i<=n;i*=2){
        if(i<n&&issmaller(people[i]->num,people[i+1]->num)){
            i++;
        }
        if(!issmaller(people[0]->num,people[i]->num))break;
        else{
            people[k]=people[i];
            k=i;
        }
    }
    people[k]=people[0];
}
void Heap(int n){
    for(int i=n/2;i>0;i--){
        AdjustHeap(i,n);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string temp1;
        cin>>temp1;
        people[i]=new Vote(temp1,i);
    }
    Heap(n);
    cout<<people[1]->index<<endl<<people[1]->num;
}