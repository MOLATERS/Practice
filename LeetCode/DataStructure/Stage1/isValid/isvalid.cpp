#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char temp,top,same;
        if(s.size()%2!=0)return false;
        for(int i=0;i<s.size()/2;i++)
        {
            temp=s[i];
            stk.push(temp);
        }
        for(int i=s.size()/2;i<s.size();i++)
        {
            temp=s[i];
            top=stk.top();
            switch(top){
                case '(':same=')';break;
                case '[':same=']';break;
                case '{':same='}';break;
                default: return false;
            }
            if(temp==same)stk.pop();
            else return false;
        }
        return true;
    }
};
main(){
    string s="{{[]}}";
    Solution a;
    bool answer;
    answer=a.isValid(s);
    return 0;
}