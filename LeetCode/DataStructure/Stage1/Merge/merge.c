#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int count=0;
    int i,j;
    int* temp=(int*)malloc(sizeof(int)*(m+n));
    for(i=0,j=0;i<m&&j<n;)
    {
        if(i<m&&j<n&&nums1[i]<nums2[j])
        {
            temp[count]=nums1[i];
            i++;
            count++;
        }
        else if(i<m&&j<n&&nums1[i]>=nums2[j])
        {
            temp[count]=nums2[j];
            j++;
            count++;
        }
    }
    while(i<m)temp[count++]=nums1[i++];
    while(j<n)temp[count++]=nums2[j++];
    for(int i=0;i<m+n;i++)
    nums1[i]=temp[i];
    free(temp);
}

int main(){
    int a[12]={1,2,5,7,0,0,0,0,0,0,0,0};
    int b[8]={1,3,6,6,8,9,9,10};
    merge(a,12,4,b,8,8);
    for(int i=0;i<12;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}