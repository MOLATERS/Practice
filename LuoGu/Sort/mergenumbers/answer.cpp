#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a,int b){
    if(!a&&b)return true;
    if(!b&&a)return false;
    int con_a[10]={0};
    int con_b[10]={0};
    int head_a=0;
    int head_b=0;
    while(a!=0){
        con_a[head_a++]=a%10;
        a=a/10;
    }
    while(b!=0){
        con_b[head_b++]=b%10;
        b=b/10;
    }
    while(head_a>=0&&head_b>=0){
        if(con_a[head_a-1]!=con_b[head_b-1])
        return con_a[head_a-1]<con_b[head_b-1];
        head_a--;
        head_b--;
    }
    return head_a>=0?false:true;
}
int main(){
    int n;
    scanf("%d",&n);
    int number[20];
    for(int i=0;i<n;i++){
        scanf("%d",&number[i]);
    }
    sort(number,number+n,compare);
    for(int i=n-1;i>=0;i--){
        printf("%d",number[i]);
    }
}