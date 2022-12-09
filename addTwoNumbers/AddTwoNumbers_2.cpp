#include <iostream>
#include <stack>
#include <queue>
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
        ListNode* tail;
        int bias=0;
        int value;
        int flag=0;//½øÎ»
        queue<ListNode*> stk1;
        queue<ListNode*> stk2;
        queue<ListNode*> stk3;
        while(num1!=NULL){
            stk1.push(num1);
            num1=num1->next;
        }
        while(num2!=NULL){
            stk2.push(num2);
            num2=num2->next;
        }
        while(!stk1.empty()&&!stk2.empty()){
            num1=stk1.front();
            num2=stk2.front();
            stk1.pop();
            stk2.pop();
            value=(num1->val+num2->val+bias)%10;
            temp=new ListNode(value);
            stk3.push(temp);
            bias=(num1->val+num2->val+bias)/10;
        }
        while(!stk1.empty()){
            num1=stk1.front();stk1.pop();
            value=(num1->val+bias)%10;
            temp=new ListNode(value);
            stk3.push(temp);
            bias=(num1->val+bias)/10;
        }
        while(!stk2.empty()){
            num2=stk2.front();stk2.pop();
            value=(num2->val+bias)%10;
            temp=new ListNode(value);
            stk3.push(temp);
            bias=(num2->val+bias)/10;
        }
        value=bias;
        answer=stk3.front();
        stk3.pop();
        ListNode* head=answer;
        while(!stk3.empty()){
            temp=stk3.front();
            stk3.pop();
            answer->next=temp;
            answer=answer->next;
        }
        if(value!=0){
            tail=new ListNode(value);
            answer->next=tail;
        }
        return head;
}
};