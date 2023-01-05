#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        stack<ListNode*> stk;
        ListNode* next;
        while(head!=nullptr&&head->val==val)head=head->next;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            if(temp->val==val)
            {
                if(!stk.empty()){
                    next=temp->next;
                    temp=stk.top();stk.pop();
                    temp->next=next;
                }
                else {
                    
                }
            }
            stk.push(temp);
            temp=temp->next;
        }
        return head;
    }
    ListNode* Create(int x,ListNode* head)
    {
        ListNode* tail=head;
        while(tail!=nullptr)tail=tail->next;
        tail=new ListNode(x);
        return head;
    }
};

main()
{
    Solution Method;
    ListNode* head=new ListNode();
    for(int i=0;i<4;i++)
    {
        ListNode* tail=head;
        while(tail!=nullptr)tail=tail->next;
        tail=new ListNode(7);
    }
    Method.removeElements(head,7);
    return 0;
}