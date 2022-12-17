#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> answer(size,1);
        for(int i=1;i<size;i++){
            answer[i]=answer[i-1]*nums[i-1];
        }
        int temp=1;
        for(int i=size-1;i>=0;i--){
            answer[i]=answer[i]*temp;
            temp=temp*nums[i];
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