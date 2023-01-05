#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //s1是s2的子串的一个排列
        unordered_map<char,int> child,window;
        int right=0;
        int left=0;
        int valid=0;
        int size1=s1.size();
        int size2=s2.size();
        for(auto x:s1){child[x]++;}
        while(right<size2){
            char temp1=s2[right];
            right++;
            if(child.count(temp1)){
                window[temp1]++;
                if(window[temp1]==child[temp1])
                valid++;
            }
            while(right-left>=size1){
                if(valid==child.size())return true;
                char temp2=s2[left];
                left++;
                if(child.count(temp2)){
                    if(window[temp2]==child[temp2])valid--;
                    window[temp2]--;
                }
            }
        }
        return false;
    }
};
main(){
    string s1="ab";
    string s2="nsialnfaladjjabsdaw";
    Solution s;
    bool answer=s.checkInclusion(s1,s2);
    if(answer)cout<<"true";
    else cout<<"false";
    return 0;
}