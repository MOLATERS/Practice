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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> stk;
        while(root!=nullptr||!stk.empty()){
                while(root==nullptr&&!stk.empty()){
                    root=stk.top()->right;
                    stk.pop();
                }
                if(root!=nullptr){
                    answer.push_back(root->val);
                    stk.push(root);
                    root=root->left;
                }
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
    Solution s;
    vector<int> answer;
    answer=s.preorderTraversal(root);
    return 0;
}