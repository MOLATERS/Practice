#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int high=nums.size()-1;
        int low=0;
        while(high>low){
            while(nums[low]<1)low++;
            while(nums[high]>=1)high--;
            if(high>low)swap(nums,high,low);
        }
        high=nums.size()-1;
        while(high>low){
            while(nums[low]==1)low++;
            while(nums[high]>1)high--;
            if(high>low)swap(nums,high,low);
        }
    }
    void swap(vector<int> &nums,int high,int low){
        int temp=nums[low];
        nums[low]=nums[high];
        nums[high]=temp;
    }
};
main(){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(0);
    // nums.push_back(2);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(1);
    Solution s;
    s.sortColors(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}