#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int index;
        vector<vector<int>> col(9,vector<int>(9,0));
        vector<vector<int>> row(9,vector<int>(9,0));
        vector<vector<vector<int>>> squ(3,vector<vector<int>>(3,vector<int>(9,0)));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]!='.')
                {
                    index=board[i][j]-'0'-1;
                    col[i][index]++;
                    row[j][index]++;
                    squ[i/3][j/3][index]++;
                    if(col[i][index]>1||row[j][index]>1||squ[i/3][j/3][index]>1)
                    return false;
                }

            }
        }
        return true;
    }
};
