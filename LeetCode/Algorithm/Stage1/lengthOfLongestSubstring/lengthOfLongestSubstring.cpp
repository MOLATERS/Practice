#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int right=0;
        int left=0;
        int answer=0;
        int size=s.size();
        while(right<size){
            char temp=s[right];
            right++;
            hash[temp]++;
            while(hash[temp]>1){
                char temp1=s[left];
                left++;
                hash[temp1]--;
            }
            answer=max(right-left,answer);
        }
        return answer;
    }
};
main(){
    string s="pwwkew";
    Solution S;
    cout<<S.lengthOfLongestSubstring(s);
    return 0;
}