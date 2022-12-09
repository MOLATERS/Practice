#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        inorder(root,answer);
        return answer;
    }
    void inorder(TreeNode* root,vector<int> &answer)
    {
        if(root==nullptr)return;
        else{
            inorder(root->left,answer);
            answer.push_back(root->val);
            inorder(root->right,answer);
        }
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
    vector<int> answer;
    answer=s.inorderTraversal(root);
    return 0;
}