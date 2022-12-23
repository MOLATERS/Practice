#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<bool> used(strs.size(),false);
        vector<vector<string>> answer;
        unordered_map<string,vector<string>> map;
        for(auto words:strs){
            map[encode(words)].push_back(words);
        }
        for(auto m:map){
            answer.push_back(m.second);
        }
        return answer;
    }
    string encode(string word){
        string encode(26,0);
        for(auto w:word){
            encode[w-'a']++;
        }
        return encode;
    }
};

int main(){
    vector<string> strs={{"cat"},{"good"},{"tac"},{"fool"},{"floo"},{"jog"},{"goj"}};
    Solution s;
    vector<vector<string>> answer;
    answer=s.groupAnagrams(strs);
    for(auto x:answer){
        cout<<'[';
        for(auto t:x){
            cout<<" "<<t<<" ";
        }
        cout<<']';
    }
}