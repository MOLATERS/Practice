#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> map;
        vector<string> words=Apart(s);
        if(words.size()!=pattern.size())return false;
        int size=pattern.size();
        for(int i=0;i<size;i++){
            for(auto it:map){
                if(it.first==pattern[i]&&it.second.compare(words[i]))
                return false;
                if(!it.second.compare(words[i])&&it.first!=pattern[i])
                return false;
            }
            map.insert(pair<char,string>(pattern[i],words[i]));
        }
        return true;
    }
    vector<string> Apart(string pattern){
        int head=0;
        int tail=0;
        int count;
        vector<string> answer;
        while(tail<pattern.size()){
            string s;
            while(pattern[tail]!=' '&&tail<pattern.size())
            tail++;
            for(int i=head;i<tail;i++){
                s.push_back(pattern[i]);
            }
            tail++;
            head=tail;
            answer.push_back(s);
        }
        return answer;
    }
};
int main(){
    string s="cat dog dog cat";
    string pattern="abba";
    Solution S;
    bool answer=S.wordPattern(pattern,s);
    if(answer)cout<<"true";
    else cout<<"false";
}
