#include <iostream>
#include <vector>
using namespace std;
/*
回溯算法的递归方式
*/
class Solution {
public:
    vector<vector<int>> answer;
    vector<int> track;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        Back(nums,used);
        return answer;
    }
    void Back(vector<int>& nums,vector<bool>& used){
        if(track.size()==nums.size()){
            answer.push_back(track);
            return;
        }
        for(int i=0;i<nums.size();i++){//回溯算法关键步骤
            if(used[i])continue;
            track.push_back(nums[i]);
            used[i]=true;
            Back(nums,used);
            track.erase(track.end()-1);
            used[i]=false;
        }
    }
};
int main(){
    vector<int> nums={1,2,3,4,5};
    Solution s;
    s.permute(nums);
    for(auto x:s.answer){
        for(auto t:x){
            cout<<t<<" ";
        }
        cout<<endl;
    }
}