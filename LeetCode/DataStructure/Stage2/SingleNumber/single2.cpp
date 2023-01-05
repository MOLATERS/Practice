#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> nums1;
        unordered_map<int,int> hash;
        long sum=0;
        long sum2=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(hash[nums[i]])continue;
            nums1.push_back(nums[i]);
            hash[nums[i]]++;
        }
        for(int i=0;i<nums1.size();i++){
            sum2=sum2+nums1[i];
        }
        return sum2*2-sum;
    }
};
main(){
    vector<int> a;
    a.push_back(100);
    for(int i=0;i<16;i++){
        a.push_back(i);
        a.push_back(i);
    }
    Solution s;
    int answer;
    answer=s.singleNumber(a);
    cout<<answer;
}