#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int head=0;
        int tail=s.size()-1;
        if(head==tail)return 0;
        vector<int> judge(tail+1,0);
        while(head<s.size()-1){
            while(tail>head){
                if(s[tail]==s[head]){
                    judge[tail]=judge[head]=1;
                    break;
                }
                else
                    tail--;
            }
                head++;
                tail=s.size()-1;
        }
        for(int i=0;i<judge.size();i++)
        {
            if(!judge[i])return i;
        }
        return -1;
    }
};

main(){
    string s="dccdbba";
    int index=0;
    Solution a;
    index=a.firstUniqChar(s);
    cout<<index<<endl;
}