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
                i++;//选择更大的那个
            }
            if(!issmaller(H[0],H[i]))break;//如果现在的对应值小于需要安排的值，就退出
            else{
                H[k]=H[i];//否则就将最初要调整的值的位置更改为当前选择的值的位置
                k=i;//将当前值再进行继续调整
            }
        }
        H[k]=H[0];//将最后的适应部分的数值返回
    }
    void swap(Student* &a,Student* &b){
        Student* temp=new Student();
        temp=a;
        a=b;
        b=temp;
    }
    void heapSort(int n){
        buildMaxHeap(n);//建立最大堆
        for(int i=n;i>n-5;i--){
            if(H[1]!=nullptr){
                cout<<H[1]->index<< " "<<H[1]->sum<<endl;
            }
            swap(H[1],H[i]);//交换最后和第一个元素
            Adjustheap(1,i-1);//对前面i-1个元素形成的堆进行调整
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