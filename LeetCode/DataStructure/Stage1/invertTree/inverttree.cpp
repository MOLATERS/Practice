#include <iostream>
#include <vector>
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        invert(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    void invert(TreeNode* &p,TreeNode*&q){
        TreeNode* temp;
        temp=p;p=q;q=temp;
    }
};

int main(){
    TreeNode* root=new TreeNode();
    TreeNode* a[10];
    for(int i =0;i<10;i++)a[i]=new TreeNode(i);
    root->left=a[1];
    root->right=a[2];
    a[1]->left=a[3];
    a[1]->right=a[4];
    Solution s;
    TreeNode* answer;
    answer=s.invertTree(root);
    return 0;
}