#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int count=0;
        for(auto x:s){
            map[x]++;
            if(map[x]==2){
                count+=2;
                map[x]=0;
            }
        }
        for(auto t:map){
            if(t.second==1){
                count++;
                break;
            }
        }
        return count;
    }
};
main(){
    string s="abccccdd";
        Solution a;
        cout<<a.longestPalindrome(s);
}