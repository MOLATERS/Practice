#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> left(size,0);
        left[0]=1;
        vector<int> right(size,0);
        right[size-1]=1;
        for(int i=1;i<size;i++){
            left[i]=left[i-1]*nums[i-1];
            right[size-1-i]=right[size-i]*nums[size-i];
        }
        vector<int> answer;
        for(int i=0;i<size;i++){
            answer.push_back(left[i]*right[i]);
        }
        return answer;
    }
};
main(){
    vector<int> nums={1,2,3,4};
    Solution s;
    vector<int> answer;
    answer=s.productExceptSelf(nums);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}