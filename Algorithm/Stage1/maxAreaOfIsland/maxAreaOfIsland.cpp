#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max=0;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]!=0){
                    Count(grid,i,j,count);
                    max=max>count?max:count;
                    count=0;
                }
            }
        }
        return max;
    }
    void Count(vector<vector<int>> &grid,int x,int y,int &count){
        if(!isvalid(grid,x,y))return;
        if(!grid[x][y])return;
        if(grid[x][y]==-1)return;
        count++;
        grid[x][y]=-1;
        Count(grid,x-1,y,count);
        Count(grid,x+1,y,count);
        Count(grid,x,y+1,count);
        Count(grid,x,y-1,count);
        grid[x][y]=0;
    }
    bool isvalid(vector<vector<int>> &grid,int x,int y){
        return x>=0&&y>=0&&x<grid.size()&&y<grid[0].size();
    }
};
main(){
    vector<vector<int>> s={{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution a;
    cout<<a.maxAreaOfIsland(s);
}