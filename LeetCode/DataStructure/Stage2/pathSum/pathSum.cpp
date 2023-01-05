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
    vector<vector<int>> answer;
    vector<int> temp;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)return answer;
        path(root,targetSum,temp);
        return answer;
    }
    void path(TreeNode* root, int targetSum,vector<int> temp) {
        if(root->val==targetSum&&root->left==nullptr&&root->right==nullptr){
            temp.push_back(root->val);
            answer.push_back(temp);
            return;
        }
        else{
            temp.push_back(root->val);
            if(root->right!=nullptr)path(root->right,targetSum-root->val,temp);
            if(root->left!=nullptr)path(root->left,targetSum-root->val,temp);
        }
        return;
    }
};
int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(9);
    // root->right->left=new TreeNode(15);
    // root->right->right=new TreeNode(7);
    Solution s;
    vector<vector<int>> answer;
    answer=s.pathSum(root,12);
        for(auto x:answer){
        for(auto t:x){
            cout<<t<<" ";
        }
        cout<<endl;
    }
    return 0;
}