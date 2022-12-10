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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk;
        Search(root,p,q,stk);
        return stk.top();
    }
    void Search(TreeNode* root,TreeNode* p,TreeNode* q,stack<TreeNode*>&stk){
        if(!root)return;
        stk.push(root);
        if(p->val==root->val){
            stk.push(p);
            return ;
        }
        else if(q->val==root->val){
            stk.push(q);
            return;
        }
        int answer1=p->val>root->val?1:-1;
        int answer2=q->val>root->val?-1:1;
        if((answer1*answer2)==1)return;
        if(p->val<root->val)Search(root->left,p,q,stk);
        else if(p->val>root->val)Search(root->right,p,q,stk);
    }
};