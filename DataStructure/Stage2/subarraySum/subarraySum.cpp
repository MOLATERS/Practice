#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int start=0;
    int count=0;
    for(;start<nums.size();start++){
        int sum=0;
        for(int end=start;end>=0;end--){
            sum+=nums[end];
            if(sum==k)count++;
        }
    }
    return count;
    }
};
main(){
    vector<int> nums={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    Solution s;
    cout<<s.subarraySum(nums,4);
}