#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=nums[0];
        int second=10000000;
        int size=nums.size();
        int point=0;
        while(point<size){
            if(nums[point]>second)return true;
            else if(nums[point]>first){
                second=nums[point];
            }
            else{
                first=nums[point];
            }
            point++;
        }
        return false;
    }
};
main(){
    vector<int> nums={5,4,3,2,1};
    Solution S;
    if(S.increasingTriplet(nums))cout<<"true";
    else cout<<"false";
}