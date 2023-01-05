#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target<matrix[0][0])return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0,j=0;
        for(;i<n;++i){
            if(matrix[j][i]==target)return true;
            if(matrix[j][i]>target)
                break;
        }
        i--;
        while(i>=0&&i<n&&j>=0&&j<m){
        {
            if(matrix[j][i]==target)return true;
            if(matrix[j][i]<target){
                j++;
                if(j>=m&&i>0){
                    j=1;
                    i--;
                }
                else if(i==0&&j>=m){
                    break;
                }
            }
            if(matrix[j][i]>target){
                j=1;
                i--;
            }
        }
    }
        return false;
    }
};
int main(){
    vector<vector<int>> matrix={{1},{1}};
    // {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    Solution s;
    bool answer=s.searchMatrix(matrix,2);
    if(answer)cout<<"true";
    else cout<<"false";
}
