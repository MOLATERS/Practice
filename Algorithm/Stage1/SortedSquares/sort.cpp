#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sub;
        vector<int> front;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                front.push_back(nums[i]*nums[i]);
            }
            else
            sub.push_back(nums[i]*nums[i]);
        }
        Reverse(sub);
        vector<int> answer;
        answer=merge(sub,front);
        return answer;
    }
    void Reverse(vector<int> &sub){
        int low=0;
        int high=sub.size()-1;
        while(low<high){
            int temp;
            temp=sub[low];
            sub[low]=sub[high];
            sub[high]=temp;
            low++;
            high--;
        }
    }
    vector<int> merge(vector<int> sub,vector<int> front){
        vector<int> merge;
        int size_sub=sub.size();
        int size_front=front.size();
        int i=0,j=0;
        while(i<size_sub&&j<size_front){
            if(sub[i]<front[j]){
                merge.push_back(sub[i]);
                i++;
            }
            else
            {
                merge.push_back(front[j]);
                j++;
            }
        }
        while(i<size_sub){
            merge.push_back(sub[i]);
            i++;
        }
        while(j<size_front){
            merge.push_back(front[j]);
            j++;
        }
        return merge;
    }
};
main(){
    vector<int> a;
    a.push_back(-3);
    // a.push_back(-1);
    a.push_back(0);
    a.push_back(2);
    // a.push_back(12);
    // a.push_back(42);
    // a.push_back(52);
    Solution s;
    vector<int> answer;
    answer=s.sortedSquares(a);
    return 0;
}