#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> answer;
    vector<int> track;
    vector<vector<int>> combine(int n, int k) {
        backtrack(1,n,k);
        return answer;
    }
    void backtrack(int start,int n,int k){
        if(k==track.size()){
            answer.push_back(track);
            return;
        }
        for(int i=start;i<=n;i++){
            track.push_back(i);
            backtrack(i+1,n,k);
            track.erase(track.end()-1);
        }
    }
};
int main(){
    Solution S;
    S.combine(10,3);
    for(auto x:S.answer){
        for(auto t:x){
            cout<<t<<" ";
        }
        cout<<endl;
    }
}