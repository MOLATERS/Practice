#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size=nums.size();
        int answer=nums[0];
        for(int i=1;i<size;i++){
            answer ^= nums[i];//ʹ�����������Խ���ʱ�临�Ӷ�
        }
        return answer;
    }
};
