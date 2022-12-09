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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        else
        return Sum(root,targetSum);
    }
    bool Sum(TreeNode* root,int targetSum){
        bool answer=false;
        if(!root){
            return false;
        }
        if(!root->left&&!root->right)
        {
            return root->val==targetSum;
        }
        else{
            targetSum-=root->val;
            answer=Sum(root->left,targetSum);
            if(answer==true)return true;
            answer=Sum(root->right,targetSum);
        }
        return answer;
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
    // TreeNode* root=new TreeNode(1);
    // root->left=new TreeNode(2);
    Solution s;
    bool answer;
    answer=s.hasPathSum(root,5);
    return 0;
}