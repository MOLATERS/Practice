#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> num;
        int colSize=matrix.size();
        int rowSize;
        int rowIndex;
        int colIndex;
        for(int i=0;i<colSize;i++)
        {
            rowSize=matrix[i].size();
            for(int j=0;j<rowSize;j++)
            {
                if(matrix[i][j]==0)num.push_back({i,j});
            }
        }
        for(int i=0;i<num.size();i++)
        {
            rowIndex=num[i][0];
            colIndex=num[i][1];
            for(int j=0;j<matrix[rowIndex].size();j++)
            matrix[rowIndex][j]=0;
            for(int k=0;k<matrix.size();k++)
            matrix[k][colIndex]=0;
        }
    }
    void setZeros2(vector<vector<int>> &matrix)
    {
        
    }
};
int main()
{
    vector<vector<int>> num={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution s;
    s.setZeroes(num);
    for(int i=0;i<num.size();i++)
    {
        for(int j=0;j<num[i].size();j++)
        {
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
}