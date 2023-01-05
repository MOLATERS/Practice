#include <vector>
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
class BSTIterator {
private:
    void inorder(TreeNode* root,vector<int>&arr){
        if(!root)return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    vector<int> GetArr(TreeNode* root){
        vector<int> arr;
        inorder(root,arr);
        return arr;
    }
    vector<int> index;
    int count;
public:
    BSTIterator(TreeNode* root):count(0),index(GetArr(root)){}
    
    int next() {
        index[count++];
    }
    
    bool hasNext() {
        return count<index.size()-1;
    }
};