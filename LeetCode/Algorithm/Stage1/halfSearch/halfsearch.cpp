#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head=0;
        int tail=nums.size()-1;
        int medium;
        while(head<tail){
            medium=(head+tail)/2;
            if(nums[medium]>target) tail=medium-1;
            else if(nums[medium]<target) head=medium+1;
            else return medium;
        }
        return -1;
    }
};
main(){
    vector<int> a;
    for(int i=0;i<10;i++)
    {
        a.push_back(i);
    }
    Solution s;
    int answer;
    answer=s.search(a,11);
    cout<<answer<<" "<<a[answer];
}