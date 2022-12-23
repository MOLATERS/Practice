#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string answer;
    string longestPalindrome(string s) {
        for(int i=0;i<s.size()-1;i++){
            find(s,i,i);
            find(s,i,i+1);
        }
        return answer;
    }
    void find(string s,int i,int j){
        string temp;
        while(s[i]==s[j]&&j<s.size()&&i>=0){
            i--;
            j++;
        }
        for(int k=i+1;k<j;k++){
            temp.push_back(s[k]);
        }
        answer=answer.size()>temp.size()?answer:temp;
    }
};
main(){
    string a="babxxxxxxxxxxxxxxxxxad";
    Solution s;
    s.longestPalindrome(a);
    cout<<s.answer;
}