#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk1;
        stack<char> stk2;
        char temp;
        char pair;
        for(int i=0;i<s.size();i++)
        {
            stk1.push(s[i]);
        }
        while(!stk1.empty())
        {
                stk2.push(stk1.top());
                stk1.pop();
            switch(temp=stk2.top()){
                case ')':pair='(';break;
                case ']':pair='[';break;
                case '}':pair='{';break;
                case '(':pair=')';break;
                case '[':pair=']';break;
                case '{':pair='}';break;
                default: return false;
            }
            if(!stk2.empty()&&stk1.top()==pair){
                stk2.pop();
                stk1.pop();
            }
        }
        if(!stk2.empty())return false;
        return true;
    }
};
main(){
    string s="{[]}";
    Solution a;
    bool answer;
    answer=a.isValid(s);
    return 0;
}