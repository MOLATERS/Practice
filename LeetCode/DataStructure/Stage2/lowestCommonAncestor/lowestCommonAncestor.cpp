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
    vector<vector<TreeNode*>> answer;
    void Find(TreeNode* root,TreeNode* target,vector<TreeNode*> arr){
        if(root==nullptr)return;
        arr.push_back(target);
        if(root==target){
            answer.push_back(arr);
            return;
        }
        Find(root->right,target,arr);
        Find(root->left,target,arr);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> temp;
        Find(root,p,temp);
        Find(root,q,temp);
        int count=0;
        int _p;
        int _q;
        while(_p==_q){
        _q=answer[1][count]->val;
        _p=answer[0][count]->val;
        count++;
        }
        return answer[0][count-1];
    }
};