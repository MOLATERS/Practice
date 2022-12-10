#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int answer=nums.size();
        int low=0;
        int high=answer-1;
        while(high>=low){
            int mid=((high-low)>>1)+low;
            if(target<=nums[mid]){
                answer=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return answer;
    }
};
main(){
    vector<int> num;
    for(int i=0;i<4;i++){
        num.push_back(2*i+1);
    }
    Solution s;
    int answer;
    answer=s.searchInsert(num,2);
    cout<<answer;
}