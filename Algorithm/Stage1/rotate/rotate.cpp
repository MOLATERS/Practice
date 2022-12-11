#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        k=k%size;
        Reverse(nums,0,size-k-1);
        Reverse(nums,size-k,size-1);
        Reverse(nums,0,size-1);
    }
    void Reverse(vector<int> &sub,int low,int high){
        while(low<high){
            int temp;
            temp=sub[low];
            sub[low]=sub[high];
            sub[high]=temp;
            low++;
            high--;
        }
    }
};