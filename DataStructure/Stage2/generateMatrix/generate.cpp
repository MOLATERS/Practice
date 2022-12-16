#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer(n,vector<int> (n,0));
        int left_high[]={0,0};
        int right_high[]={0,n-1};
        int left_low[]={n-1,0};
        int right_low[]={n-1,n-1};
        int count=1;
        while(left_high[1]<=right_high[1]&&left_low[1]<=right_low[1]){
            for(int i=left_high[1];i<=right_high[1];i++){
                answer[left_high[0]][i]=count;
                count++;
            }
                left_high[0]++;
                left_high[1]++;
                right_high[0]++;
                right_high[1]--;
            for(int i=right_high[0];i<=right_low[0];i++){
                answer[i][right_low[1]]=count;
                count++;
            }
                right_low[1]--;
                right_low[0]--;
            for(int i=right_low[1];i>=left_low[1];i--){
                answer[left_low[0]][i]=count;
                count++;
            }
                left_low[0]--;
            for(int i=left_low[0];i>=left_high[0];i--){
                answer[i][left_low[1]]=count;
                count++;
            }
                left_low[1]++;
        }
        return answer;
    }
};
main(){
    vector<vector<int>> answer;
    Solution s;
    answer=s.generateMatrix(4);
    for(int i=0;i<answer.size();i++){
        cout<<endl;
        for(int j=0;j<answer.size();j++){
            cout<<answer[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}