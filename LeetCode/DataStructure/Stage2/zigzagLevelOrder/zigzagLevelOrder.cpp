#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        bool flag=true;
        que.push(root);
        vector<vector<int>> answer;
        if(root==nullptr)return answer;
        while(!que.empty()){
            int size=que.size();
            flag=!flag;
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* temp=que.front();que.pop();
                level.push_back(temp->val);
                if(temp->left!=nullptr)que.push(temp->left);
                if(temp->right!=nullptr)que.push(temp->right);
            }
            if(flag)Reverse(level);
            answer.push_back(level);
        }
        return answer;
    }
    void Reverse(vector<int>& level){
        int right=level.size()-1;
        int left=0;
        while(left<right){
            int temp=level[right];
            level[right]=level[left];
            level[left]=temp;
            left++;
            right--;
        }
    }
};
int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    Solution s;
    vector<vector<int>> answer=s.zigzagLevelOrder(root);
    for(auto x:answer){
        for(auto t:x){
            cout<<t<<" ";
        }
        cout<<endl;
    }
    return 0;
}