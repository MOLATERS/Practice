#include <iostream>
using namespace std;
int nums[100000];
void quickSort(int left,int right){
        if(left<right){
        int i=left;
        int j=right;
        int mid=(left+right)/2;
        swap(nums[left],nums[mid]);
        int x=nums[left];
        while(i<j){
            while(i<j&&nums[j]>=x){
                j--;
            }
            if(i<j){
                nums[i++]=nums[j];
            }
            while(i<j&&nums[i]<x){
                i++;
            }
            if(i<j){
                nums[j--]=nums[i];
            }
        }
        nums[i]=x;
        quickSort(left,i-1);
        quickSort(i+1,right);
        }
    }
void swap(int&a,int&b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    quickSort(0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}