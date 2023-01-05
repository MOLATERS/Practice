#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        stack<ListNode*> stk;
        bool flag=false;
        while(temp!=nullptr){
            if(stk.empty()&&temp!=nullptr){
                stk.push(temp);
                temp=temp->next;
            }
            while(temp!=nullptr&&stk.top()->val==temp->val){
                temp=temp->next;
                flag=true;
            }
            if(flag){
                stk.pop();
                flag=false;
            }
            stk.push(temp);
            if(temp!=nullptr){
                temp=temp->next;
            }
        }
        while(!stk.empty()){
            ListNode* next=stk.top();stk.pop();
            head=next;
            if(!stk.empty())stk.top()->next=next;
        }
        return head;
    }
};
main(){
        ListNode* headA=new ListNode(9);
    ListNode* root1=headA;
    for(int i=9;i>4;i--){
        headA->next=new ListNode(i);
        headA=headA->next;
    }
    for(int i=0;i<3;i++){
        headA->next=new ListNode(5);
        headA=headA->next;
    }
    Solution s;
    s.deleteDuplicates(root1);
}