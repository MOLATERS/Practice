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
    vector<int> nums={1,0,1,2,0,0,4,6};
    Solution s;
    s.moveZeroes(nums);
    for(auto x:nums){
        cout<<x<<" ";
    }
    return 0;
}