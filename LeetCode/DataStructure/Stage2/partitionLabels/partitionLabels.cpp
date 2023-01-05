#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int left=0;
        int right=0;
        vector<int> answer;
        unordered_map<char,int> map;
        for(int i=0;i<s.size();i++){
            map[s[i]]=i;
        }
        while(right<s.size()-1){
            right=map[s[left]];
            for(int i=left;i<right;i++)
            right=right>map[s[i]]?right:map[s[i]];
            answer.push_back(right-left+1);
            left=right+1;
        }
        return answer;
    }
};
int main(){
    string s="absabsbabbbddddjkldnmnmnmnmnmmm";
    vector<int> answer;
    Solution S;
    answer=S.partitionLabels(s);
    for(auto it:answer){
        cout<<it<<" ";
    }
    return 0;
}