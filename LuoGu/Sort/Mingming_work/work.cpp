#include <iostream>
using namespace std;
bool nums[1002]={false};
int n;
int sum=0;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(!nums[temp]){
            nums[temp]=true;
            sum++;
        }
    }
    printf("%d\n",sum);
    for(int i=1;i<1000;i++){
        if(nums[i])printf("%d ",i);
    }
    printf("\n");
}