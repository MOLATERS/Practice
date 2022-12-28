#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        int pointer=0;
        int size=s.size();
        vector<int> valid(size,1);
        string answer;
        for(;pointer<size;pointer++){
            if(s[pointer]=='(')stk.push(pointer);
            else if(stk.empty()&&s[pointer]==')')valid[pointer]=0;
            else if(!stk.empty()&&s[pointer]==')')stk.pop();
        }
        while(!stk.empty()){
            pointer=stk.top();
            valid[pointer]=0;
            stk.pop();
        }
        for(int i=0;i<size;i++){
            if(valid[i])answer.push_back(s[i]);
        }
        return answer;
    }
};

int main(){
    string s="(123)))234ad(sd)sfs)(hda)";
    Solution S;
    cout<<S.minRemoveToMakeValid(s);
    return 0;
}