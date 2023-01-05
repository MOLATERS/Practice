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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<int> answer;
        if(!root)return answer;
        while(!que.empty()){
            int size=que.size();
            int last;
            for(int i=0;i<size;i++){
                TreeNode* temp=que.front();que.pop();
                if(i==size-1)last=temp->val;
                if(temp->left!=nullptr)que.push(temp->left);
                if(temp->right!=nullptr)que.push(temp->right);
            }
            answer.push_back(last);
        }
        return answer;
    }
};
int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    Solution s;
    vector<int> answer=s.rightSideView(root);
    for(auto x:answer){
            cout<<x<<" ";
    }
    return 0;
}