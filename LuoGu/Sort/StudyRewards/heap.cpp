#include <iostream>
using namespace std;
struct Student{
    int index; 
    int sum;
    int chinese;
    Student():sum(0),index(0),chinese(0){}
    Student(int x,int y,int z):index(x),sum(y),chinese(z){}
};
Student* H[10000]={new Student()};
class Heap{
public:
    void buildMaxHeap(int n){
        for(int i=n/2;i>0;i--){
            Adjustheap(i,n);
        }
    }
    bool issmaller(Student* x,Student* y){
        if(!x||!y)return false;
        if(x->sum>y->sum)return false;
        else if(x->sum<y->sum)return true;
        else{
            if(x->chinese>y->chinese)return false;
            else if(x->chinese<y->chinese)return true;
            else{
                if(x->index<y->index)return false;
                else return true;
            }
        }
    }
    void Adjustheap(int k,int n){
        H[0]=H[k];
        int i;
        for(i=2*k;i<=n;i*=2){
            if(i<n&&issmaller(H[i],H[i+1])){
                i++;
            }
            if(!issmaller(H[0],H[i]))break;
            else{
                H[k]=H[i];
                k=i;
            }
        }
        H[k]=H[0];
    }
    void swap(Student* &a,Student* &b){
        Student* temp=new Student();
        temp=a;
        a=b;
        b=temp;
    }
    void heapSort(int n){
        buildMaxHeap(n);
        for(int i=n;i>n-5;i--){
            if(H[1]!=nullptr){
                cout<<H[1]->index<< " "<<H[1]->sum<<endl;
            }
            swap(H[1],H[i]);
            Adjustheap(1,i-1);
        }
    }
};
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp1;
        int temp2;
        int temp3;
        cin>>temp1>>temp2>>temp3;
        Student* temp=new Student(i,temp1+temp2+temp3,temp1);
        H[i]=temp;
    }
    Heap s;
    s.heapSort(n);
    return 0;
}