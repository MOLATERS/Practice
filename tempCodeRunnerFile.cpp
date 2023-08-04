#include <iostream>
#include <random>
using namespace std;
float H[20000]
//这是你们给出来的函数,注意要将H[0]转变成没有有效数字的形式
class Heap{
public:
    void buildMaxHeap(int n){
        for(int i=n/2;i>0;i--){
            Adjustheap(i,n);
        }
    }
    bool issmaller(float x,float y){
       return x<y;
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
    void swap(float &a,float &b){
        float temp=a;
        a=b;
        b=temp;
    }
    void heapSort(int n){
        buildMaxHeap(n);//建立最大堆
        for(int i=n;i>n-5;i--){
            if(H[1]!=nullptr){
                cout<<H[1]<<endl;
            }
            swap(H[1],H[i]);//交换最后和第一个元素
            Adjustheap(1,i-1);//对前面i-1个元素形成的堆进行调整
        }
    }
};

//调用方法

int main(){
    int n=50;//输入的数据的长度
    for(int i=1; i<=n;i++){
        H[i]=rand()%100;
    }
    Heap S;
    S.heapSort(n);
    if (H[2]>H[3]){
        cout<<H[1]<<H[2]<<endl;
    }
    else{
        cout<<H[1]<<H[3]<<endl;
    }
}