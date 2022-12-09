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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* num1=l1;
        ListNode* num2=l2;
        ListNode* answer;
        ListNode* temp;
        int bias=0;
        int value;
        stack<ListNode*> stk1;
        stack<ListNode*> stk2;
        stack<ListNode*> stk3;
        while(num1!=NULL){
            stk1.push(num1);
            num1=num1->next;
        }
        while(num2!=NULL){
            stk2.push(num2);
            num2=num2->next;
        }
        while(!stk1.empty()&&!stk2.empty()){
            num1=stk1.top();
            num2=stk2.top();
            stk1.pop();
            stk2.pop();
            value=(num1->val+num2->val+bias)%10;
            temp=new ListNode(value);
            stk3.push(temp);
            bias=(num1->val+num2->val+bias)/10;
        }
        while(!stk1.empty()){
            num1=stk1.top();stk1.pop();
            value=(num1->val+bias)%10;
            temp=new ListNode(value);
            stk3.push(temp);
            bias=(num1->val+bias)/10;
        }
        while(!stk2.empty()){
            num2=stk2.top();stk2.pop();
            value=(num2->val+bias)%10;
            temp=new ListNode(value);
            stk3.push(temp);
            bias=(num2->val+bias)/10;
        }
        if(bias==0)
        {
            answer=stk3.top();
            stk3.pop();
        }
        else
        answer=new ListNode(bias);
        ListNode* head=answer;
        while(!stk3.empty()){
            temp=stk3.top();
            stk3.pop();
            answer->next=temp;
            answer=answer->next;
        }
        return head;
}
};