#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 */
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)return root2;
        if(!root2)return root1;
        TreeNode* merge=new TreeNode(root1->val+root2->val);
        merge->left=mergeTrees(root1->left,root2->left);
        merge->right=mergeTrees(root1->right,root2->right);
        return merge;
    }
    // TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    //     TreeNode* answer;
    //     Merge(answer,root1,root2);
    //     return answer;
    // }
    void Merge(TreeNode* &answer,TreeNode* root1,TreeNode* root2){
        if(root1||root2){
            answer=new TreeNode();
            int val_1=root1?root1->val:0;
            int val_2=root2?root2->val:0;
            answer->val=val_1+val_2;
            TreeNode* root2_left=root2?root2->left:nullptr;
            TreeNode* root2_right=root2?root2->right:nullptr;
            TreeNode* root1_left=root1?root1->left:nullptr;
            TreeNode* root1_right=root1?root1->right:nullptr;
            Merge(answer->left,root1_left,root2_left);
            Merge(answer->right,root1_right,root2_right);
        }
        return ;
    }
    // TreeNode* Merge(TreeNode* &answer,TreeNode* root1,TreeNode* root2){
    //     if(root1&&root2){
    //         answer=new TreeNode();
    //         answer->val=root1->val+root2->val;
    //         answer->left=Merge(answer->left,root1->left,root2->left);
    //         answer->right=Merge(answer->right,root1->right,root2->right);
    //     }
    //     else if(!root1&&root2){
    //         answer=new TreeNode();
    //         answer->val=root2->val;
    //         answer->left=Merge(answer->left,nullptr,root2->left);
    //         answer->right=Merge(answer->right,nullptr,root2->right);
    //     }
    //     else if(root1&&!root2){
    //         answer=new TreeNode();
    //         answer->val=root1->val;
    //         answer->left=Merge(answer->left,root1->left,nullptr);
    //         answer->right=Merge(answer->right,root1->right,nullptr);
    //     }
};
class Tree{
public:
    void preorder(TreeNode* root){
        if(!root){
            return;
        }
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
};
int main(){
    TreeNode* root1;
    root1=new TreeNode(1);
    root1->left=new TreeNode(3);
    root1->right=new TreeNode(2);
    root1->left->left=new TreeNode(5);
    TreeNode* root2=new TreeNode(2);
    root2->left=new TreeNode(1);
    root2->right=new TreeNode(3);
    root2->left->right=new TreeNode(4);
    root2->right->right=new TreeNode(7);
    Solution s;
    Tree T;
    TreeNode* answer=s.mergeTrees(root1,root2);
    T.preorder(root1);cout<<endl;
    T.preorder(root2);cout<<endl;
    T.preorder(answer);
    return 0;
}