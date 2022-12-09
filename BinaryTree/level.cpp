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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
        {
            return ret;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=1;i<=size;i++){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        ret.push_back(temp);
        }
        return ret;
    }
};
int main(){
    TreeNode* root=new TreeNode();
    TreeNode* a[10];
    for(int i =0;i<10;i++){
        a[i]=new TreeNode(i);
    }
    root->left=a[1];
    root->right=a[2];
    a[1]->left=a[3];
    a[1]->right=a[4];
    Solution s;
    vector<vector<int>> answer;
    answer=s.levelOrder(root);
    return 0;
}