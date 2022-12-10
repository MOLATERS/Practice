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
        int flag=0;
        ListNode* head;
        while(num1!=NULL&&num2!=NULL){
            value=(num1->val+num2->val+bias)%10;
            bias=(num1->val+num2->val+bias)/10;
            if(flag==0){
                answer=new ListNode(value);
                head=answer;
                flag=1;
            }
            else{
                answer->next=new ListNode(value);
                answer=answer->next;
            }
            num1=num1->next;
            num2=num2->next;
        }
        while(num1!=NULL){
            value=(num1->val+bias)%10;
            bias=(num1->val+bias)/10;
            answer->next=new ListNode(value);
            answer=answer->next;
            num1=num1->next;
        }
        while(num2!=NULL){
            value=(num2->val+bias)%10;
            bias=(num2->val+bias)/10;
            answer->next=new ListNode(value);
            answer=answer->next;
            num2=num2->next;
        }
        value=bias;
        if(value!=0){
            tail=new ListNode(value);
            answer->next=tail;
        }
        return head;
}
};

main()
{
    int num1;
    int num2;
    ListNode* l1;
    ListNode* l2;
    ListNode* temp;
    ListNode* lhead;
    ListNode* l2head;
    cout<<"Please input the first size: ";
    cin>>num1;
    cout<<"Please input the second size: ";
    cin>>num2;
    for(int i=0;i<num1;i++)
    {
        if(i==0)
        {
            l1=new ListNode(i);
            lhead=l1;
            continue;
        }
        l1->next=new ListNode(i);
        l1=l1->next;
    }
    for(int j=0;j<num2;j++)
    {
        if(j==0){
            l2=new ListNode(j);
            l2head=l2;
            continue;
        }
        temp=new ListNode(j);
        l2->next=temp;
        l2=l2->next;
    }
    Solution a;
    a.addTwoNumbers(lhead,l2head);
}