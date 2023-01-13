#include <iostream>
using namespace std;
int nums[50000005];
int k=0;
void KthMinimum(int left,int right){
    if(left<right){
        int i=left;
        int j=right;
        int mid=(right+left)/2;
        swap(nums[mid],nums[left]);
        int x=nums[left];
        while(i<j){
            while(i<j&&nums[j]>x)j--;
            if(i<j)nums[i++]=nums[j];
            while(i<j&&nums[i]<=x)i++;
            if(i<j)nums[j--]=nums[i];
        }
        nums[i]=x;
        if(i>k)KthMinimum(left,i);
        else if(i<k)KthMinimum(i,right);
        else{printf("%d",nums[i]);exit(0);}
    }
}
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int n;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    KthMinimum(0,n-1);
    return 0;
}