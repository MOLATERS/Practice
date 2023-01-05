#include <string>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int c=0;
        int temp;
        stack<int> stk;
        string answer="";
        while(i>=0&&j>=0){
            int n1=num1[i]-'0';
            int n2=num2[j]-'0';
            temp=(n1+n2+c)%10;
            stk.push(temp);
            c=(n1+n2+c)/10; 
            i--;j--;
        }
        while(i>=0){
            temp=(num1[i]-'0'+c)%10;
            stk.push(temp);
            c=(num1[i]-'0'+c)/10;i--;
        }
        while(j>=0){
            temp=(num2[j]-'0'+c)%10;
            stk.push(temp);
            c=(num2[j]-'0'+c)/10;j--;
        }
        if(c!=0)stk.push(c);
        while(!stk.empty()){
            char p='0'+stk.top();
            stk.pop();
            answer.push_back(p);
        }
        return answer;
    }
};
main(){
    string num1="584";
    string num2="18";
    string answer;
    Solution s;
    answer=s.addStrings(num1,num2);
    cout<<answer;
    return 0;
}