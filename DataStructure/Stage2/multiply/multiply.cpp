#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
        int m=num1.size();
        int n=num2.size();
        string summary;
        vector<int> answer(m+n,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int place1=i+j;
                int place2=i+j+1;
                int sum=(num1[i]-'0')*(num2[j]-'0')+answer[place2];
                answer[place2]=sum%10;
                answer[place1]+=sum/10;
            }
        }
        int i=0;
        for(;answer[i]==0&&i<m+n;i++);
        for(;i<m+n;i++){
            summary.push_back('0'+answer[i]);
        }
        return summary;
    }
};
int main(){
    string num1="0";
    string num2="0";
    Solution S;
    cout<<S.multiply(num1,num2);
}