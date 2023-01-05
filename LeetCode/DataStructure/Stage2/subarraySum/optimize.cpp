#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int pre=0;
        int count=0;
        map[0]=1;
        for(int i=0;i<nums.size();i++){
            pre=pre+nums[i];
            if(map.find(pre-k)!=map.end()){
                count+=map[pre-k];
            }
            map[pre]++;
        }
        return count;
    }
};
main(){
    vector<int> nums={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    Solution s;
    cout<<s.subarraySum(nums,4);
}