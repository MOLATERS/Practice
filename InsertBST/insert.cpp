#include <iostream>
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* head=root;
        TreeNode* temp;
        if(head==nullptr)return root=new TreeNode(val);
        while(head!=nullptr){
            temp=head;
            head=head->val<val?head->right:head->left;
        }
        if(temp->val<val){
            head=new TreeNode(val);
            temp->right=head;
        }
        else{
            head=new TreeNode(val);
            temp->left=head;
        }
        return root;
    }
};