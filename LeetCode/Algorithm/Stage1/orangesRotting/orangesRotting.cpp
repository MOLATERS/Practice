#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row_size=grid.size();
        int col_size=grid[0].size();
        int g=0;
        vector<int> dir={-1,0,1,0,-1};
        queue<pair<int,int>> que;
        int count=-1;
        vector<vector<int>> flag(row_size,vector<int>(col_size,0));
        for(int i=0;i<row_size;i++){
            for(int j=0;j<col_size;j++){
                if(grid[i][j]==0)flag[i][j]=1;
                if(grid[i][j]==1)g=1;
                if(grid[i][j]==2){
                    que.emplace(i,j);
                    flag[i][j]=1;
                }
            }
        } 
        if(!g)return 0;
        while(!que.empty()){
            int size=que.size();
            for(int k=0;k<size;k++){
                auto [i,j]=que.front();
                que.pop();
                for(int t=0;t<4;t++){
                    int row=i+dir[t];
                    int col=j+dir[t+1];
                    if(row>=0&&col>=0
                    &&row<row_size&&
                    col<col_size&&!flag[row][col]){
                        grid[row][col]=2;
                        flag[row][col]=1;
                        que.emplace(row,col);
                    }
                }
            }
            count++;
        }
        for(int i=0;i<row_size;i++){
            for(int j=0;j<col_size;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return count;
    }
};