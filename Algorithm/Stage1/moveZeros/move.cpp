#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p=setplace(nums,0);
        for(;p<nums.size();p++){
            nums[p]=0;
        }
        return ;
    }
    int setplace(vector<int>& nums,int val){
        int high=0;int low=0;
        while(high<nums.size()){
            if(nums[high]!=val){
                nums[low]=nums[high];
                low++;
            }
            high++;
        }
        return low;
    }
};
main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(4);
    nums.push_back(6);
    Solution s;
    s.moveZeroes(nums);
    return 0;
}