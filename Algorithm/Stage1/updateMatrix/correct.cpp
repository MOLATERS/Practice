#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> flag(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<int,int>> que;
        vector<int> dir={-1,0,1,0,-1};
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0)
                {
                    flag[i][j]=1;
                    que.emplace(i,j);
                }
            }
        }
        while(!que.empty()){
                auto [i,j]=que.front();que.pop();
                for(int d=0;d<4;d++){
                    int row=i+dir[d];
                    int col=j+dir[d+1];
                    if(row>=0&&col>=0&&row<mat.size()&&col<mat[0].size()&&!flag[row][col]){
                        mat[row][col]=mat[i][j]+1;
                        que.emplace(row,col);
                        flag[row][col]=1;
                    }
                }
            }
        return mat;
    }
};
void show(vector<vector<int>> answer){
    for(auto x:answer){
        for(auto t:x){
            cout<<t<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    vector<vector<int>> answer;
    vector<vector<int>> mat={{1,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,1}};
    Solution s;
    show(mat);
    answer=s.updateMatrix(mat);
    show(answer);
}