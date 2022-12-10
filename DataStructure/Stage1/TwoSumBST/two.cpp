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
    bool findTarget(TreeNode* root, int k) {
        vector<int> c;
        search(root,c);
        int head=0;int tail=c.size()-1;
        int temp_head=head;
        int temp_tail=tail;
        while(head<tail){
            while(c[head]+c[tail]!=k&&head<tail-1){
                tail--;
            }
            if(c[head]+c[tail]==k)return true;
            head++;
            tail=temp_tail;
        }
        return false;
    }
    void search(TreeNode* root,vector<int>&c){
        if(!root)return;
        search(root->left,c);
        c.push_back(root->val);
        search(root->right,c);
    }
};