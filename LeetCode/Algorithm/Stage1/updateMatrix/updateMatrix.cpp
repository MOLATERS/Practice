#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> answer(mat);
        queue<vector<int>> que;
        int count=1;
        for(int i=0;i<answer.size();i++){
            for(int j=0;j<answer[i].size();j++){
                if(answer[i][j]==0)
                {
                    mat[i][j]=-1;
                    que.push({i,j});
                }
            }
        }
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                vector<int> temp=que.front();
                que.pop();
                if(Isvalid(temp[0]-1,temp[1],answer)&&mat[temp[0]-1][temp[1]]!=-1)
                {
                    answer[temp[0]-1][temp[1]]=count;
                    que.push({temp[0]-1,temp[1]});
                    mat[temp[0]-1][temp[1]]=-1;
                }
                if(Isvalid(temp[0]+1,temp[1],answer)&&mat[temp[0]+1][temp[1]]!=-1)
                {
                    answer[temp[0]+1][temp[1]]=count;
                    que.push({temp[0]+1,temp[1]});
                    mat[temp[0]+1][temp[1]]=-1;
                }
                if(Isvalid(temp[0],temp[1]-1,answer)&&mat[temp[0]][temp[1]-1]!=-1)
                {
                    answer[temp[0]][temp[1]-1]=count;
                    que.push({temp[0],temp[1]-1});
                    mat[temp[0]][temp[1]-1]=-1;
                }
                if(Isvalid(temp[0],temp[1]+1,answer)&&mat[temp[0]][temp[1]+1]!=-1)                
                {
                    answer[temp[0]][temp[1]+1]=count;
                    que.push({temp[0],temp[1]+1});
                    mat[temp[0]][temp[1]+1]=-1;
                }
            }
            count++;
        }
        return answer;
    }
    bool Isvalid(int i,int j,vector<vector<int>> answer){
        return i>=0&&j>=0&&i<answer.size()&&j<answer[0].size();
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