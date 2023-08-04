#include <iostream>
#include <random>
#include <time.h>
using namespace std;
typedef double stastics;
//这是你们给出来的函数,注意要将H[0]转变成没有有效数字的形式
class Heap{
public:
    // float H[20000]={0};
    void buildMaxHeap(int n,float* H){
        for(int i=n/2;i>0;i--){
            Adjustheap(i,n,H);
        }
    }
    bool issmaller(float x,float y){
       return x<y;
    }
    void Adjustheap(int k,int n,float* H){
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
    void heapSort(int n,float* H){
        buildMaxHeap(n,H);//建立最大堆
        for(int i=n;i>0;i--){
            if(H[1]!=0){
                // cout<<H[1]<<endl;
            }
            swap(H[1],H[i]);//交换最后和第一个元素
            Adjustheap(1,i-1,H);//对前面i-1个元素形成的堆进行调整
        }
    }
    float* FindMax2(int n,float* H,float* answer){
        heapSort(n,H);
        answer[0]=H[n];
        answer[1]=H[n-1];
        // cout<<H[n]<<" "<<H[n-1]<<endl;
        // cout<<answer[0]<<" "<<answer[1]<<endl;
        return answer;
    }
};

bool check(float* answer,float* H,int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<2;j++){

        }
    }
}
//调用方法

int main(){
    float answer[2]={0};//定义出的数组 *need
    float H[2000]={0};//定义入的数组 *need
    int n=50;//输入的数据的长度 *need

    //数据验证

    srand(time(0));//用于数据验证的时候使用的随机数种子
    for(int i=1; i<=n;i++){
        H[i]=rand()%100+1;
    }

    //调用方法

    Heap S;//实例化
    S.FindMax2(n,H,answer);
    for(int i=1; i<=n;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<=1;i++){
        cout<<answer[i]<<" ";
    }

}