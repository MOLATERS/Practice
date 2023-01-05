#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        int step=k%(n+1);
        queue<int> Q;
        for(int i=1;i<=n;i++){
            Q.push(i);
        }
        while(Q.size()>1){
            for(int i=0;i<step-1;i++){
                Q.push(Q.front());
                Q.pop();
            }
            Q.pop();
        }
        return Q.front();
    }
};
int main(){
    Solution s;
    cout<<s.findTheWinner(8,8);
    return 0;
}