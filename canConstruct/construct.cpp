#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hash;
        for(int i=0;i<magazine.size();i++)
        {
            hash[magazine[i]]++;
        }
        for(int j=0;j<ransomNote.size();j++)
        {
            if(hash[ransomNote[j]]==0)return false;
            else
            {
                hash[ransomNote[j]]--;
            }
        }
        return true;
    }
};
main()
{
    bool correct;
    string a="a";
    string b="ab";
    Solution s;
    correct=s.canConstruct(a,b);
    if(correct)cout<<"true";
    else cout<<"false";
    return 0;
}