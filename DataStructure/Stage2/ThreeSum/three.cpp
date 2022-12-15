#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        int second;
        int third;
        int first = 0;
        int size = nums.size();
        if(size<3)return answer;
        sort(nums.begin(),nums.end());
        if(nums[0]>0)return answer;
        while(first<=size-3){
            int temp_first=first;
            second=first+1;
            third=size-1;
            while(second<third){
                if(nums[first]+nums[second]+nums[third]<0){
                    do {
                        second++;
                    } while (nums[second] == nums[second + 1]);
                }
                else if (nums[first]+nums[second]+nums[third]>0){
                do{
                    third--;
                }while(nums[third]==nums[third-1]);
                }
                else{
                    vector<int> temp;
                    temp.push_back(nums[first]);
                    temp.push_back(nums[second]);
                    temp.push_back(nums[third]);
                    second++;
                    if(Compare(answer,temp))continue;
                    answer.push_back(temp);
                }
            }
            do{
                first++;
            }while(nums[first]==temp_first);
        }
        return answer;
    }
    bool compare(vector<int> num1,vector<int> num2){
        int size1=num1.size();
        int size2=num2.size();
        if(size1!=size2)return false;
        for(int i=0;i<size1;i++){
            if(num1[i]!=num2[i])return false;
        }
        return true;
    }
    bool Compare(vector<vector<int>> num,vector<int> temp){
        bool answer=false;
        for(int i=0;i<num.size();i++)
        {
            answer=answer||compare(num[i],temp);
        }
        return answer;
    }
};
int main(){
    vector<int> num={0,0,0,0};
    Solution S;
    vector<vector<int>> answer;
    answer=S.threeSum(num);
    for(int i=0;i<answer.size();i++)
    {
        for(int j=0;j<answer[i].size();j++)
        {
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}