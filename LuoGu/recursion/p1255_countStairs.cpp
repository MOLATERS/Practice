#include <iostream>
using namespace std;
int n,length=1,function[5004][5004]={0};//第一个下标表示到第几级台阶，其余的位数就是数字
void count(int step){
    for(int i=1;i<=length;i++){
        function[step][i]=function[step-1][i]+function[step-2][i];
    }
    for(int i=1;i<=length;i++){
        if(function[step][i]>=10){
            function[step][i+1]+=function[step][i]/10;
            function[step][i]=function[step][i]%10;
            if(function[step][length+1])length++;
        }
    }
}
int main(){
    scanf("%d",&n);
    function[1][1]=1;
    function[2][1]=2;
    for(int i=3;i<=n;i++)
    count(i);
    for(int i=length;i>=1;i--){
        cout<<function[n][i];
    }
    return 0;
}
