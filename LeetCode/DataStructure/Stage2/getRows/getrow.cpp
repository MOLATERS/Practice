#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer;
        answer.push_back(1);
        if(rowIndex==0)return answer;
        vector<int> pre=getRow(rowIndex-1);
        for(int i=0;i<pre.size()-1;i++){
            answer.push_back(pre[i]+pre[i+1]);
        }
        answer.push_back(1);
        return answer;
    }
};
main(){
    vector<int> answer;
    Solution S;
    answer=S.getRow(6);

    for(int i=0;i<answer.size();i++)
    cout<<" " <<answer[i];
    return 0;
}