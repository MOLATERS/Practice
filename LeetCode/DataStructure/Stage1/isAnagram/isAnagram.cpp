#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> hash;
        int sizeS=s.size();
        int sizeT=t.size();
        if(sizeS!=sizeT)return false;
        for(int i=0;i<sizeS;i++){
            hash[s[i]]++;
        }
        for(int i=0;i<sizeT;i++)
        {
            if(hash[t[i]]==0)return false;
            hash[t[i]]--;
        }
        for(int i=0;i<sizeS;i++)
        {
            if(hash[s[i]]>0)return false;
        }
        return true;
    }
};
main()
{
    string s1="anagram";
    string s2="nagaram";
    bool answer;
    Solution a;
    answer=a.isAnagram(s1,s2);
    if(answer)cout<<"true";
    else cout<<"false";
}