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
    bool isValidBST(TreeNode* root) {
        vector<int> c;
        insearch(root,c);
        int size=c.size();
        for(int i=0;i<size-1;i++){
            if(c[i]>=c[i+1])return false;
        }
        return true;
    }
    void insearch(TreeNode* root,vector<int> &c){
        if(!root)return;
        insearch(root->left,c);
        c.push_back(root->val);
        insearch(root->right,c);
    }
};