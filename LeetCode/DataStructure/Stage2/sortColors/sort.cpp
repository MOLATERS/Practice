#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int high=nums.size()-1;
        int low=0;
        int point=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[point]==0){
                swap(nums,point,low);
                low++;
            }
            else if(nums[point]==2){
                swap(nums,point,high);
                high--;
            }
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
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    Solution s;
    s.sortColors(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}