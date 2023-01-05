#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
    void Create(Node* &root,vector<int> num,int index){
        if(index>num.size()-1)return;
        root=new Node(num[index]);
        Create(root->left,num,index*2+1);
        Create(root->right,num,index*2+2);
    }
    void Read(Node* root){
        if(!root)return ;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            Node* node=que.front();que.pop();
            cout<<node->val<<" ";
            if(node->next==nullptr)cout<<'#'<<" ";
            if(node->left!=nullptr)que.push(node->left);
            if(node->right!=nullptr)que.push(node->right);
        }
    }
};
class Solution {
public:
    Node* connect(Node* &root) {
        if(!root)return nullptr;
        queue<Node*> que;
        que.push(root);
        int size;
        while(!que.empty()){
            size=que.size();
            for(int i=0;i<size;i++){
                Node* temp=que.front();
                que.pop();
                if(i<size-1){
                    temp->next=que.front();
                }
                if(temp->left!=nullptr)
                que.push(temp->left);
                if(temp->right!=nullptr)
                que.push(temp->right);
            }
        }
        return root;
    }
};
main(){
    vector<int> num={1,2,3,4,5,6,7};
    Node* root;
    root->Create(root,num,0);
    Solution s;
    s.connect(root);
    root->Read(root);
}