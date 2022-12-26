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
    void reorderList(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* pointer1=head;
        ListNode* pointer2=head;
        while(pointer2!=nullptr){
            stk.push(pointer2);
            pointer2=pointer2->next;
        }
        while(pointer1!=nullptr&&pointer1->next!=nullptr&&pointer1!=pointer2&&pointer1->next!=pointer2){
            pointer2=stk.top();stk.pop();
            stk.top()->next=nullptr;
            insert(pointer1,pointer2);
            pointer1=pointer1->next->next;
        }
    }
    void insert(ListNode*&target,ListNode*&insert){
        if(target->next==nullptr){
            target->next=insert;
        }
        else{
            ListNode* temp=target->next;
            target->next=insert;
            insert->next=temp;
        }
    }
};
int main(){
    ListNode* headA=new ListNode(0);
    ListNode* root1=headA;
    for(int i=9;i>3;i--){
        headA->next=new ListNode(i);
        headA=headA->next;
    }
    Solution s;
    s.reorderList(root1);
    return 0;
}