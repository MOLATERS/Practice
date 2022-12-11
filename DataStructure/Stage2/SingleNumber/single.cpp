#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size=nums.size();
        int answer=nums[0];
        for(int i=1;i<size;i++){
            answer ^= nums[i];//使用异或运算可以降低时间复杂度
        }
        return answer;
    }
};
