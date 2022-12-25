//
// Created by Slater on 12/23/2022.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> stkA;
        stack<ListNode*> stkB;
        ListNode* root1=headA;
        ListNode* root2=headB;
        while(headA!=nullptr)
        {stkA.push(headA);headA=headA->next;}
        while(headB!=nullptr)
        {stkB.push(headB);headB=headB->next;}
        while(true){
            if(stkA.empty()||stkB.empty())break;
            if(stkA.top()!=stkB.top())break;
            if(stkA.top()==stkB.top()){
                stkA.pop();
                stkB.pop();
            }
        }
        if(stkA.empty())return root1;
        if(stkB.empty())return root2;
        return stkA.top()->next;
    }
};
int main(){
    ListNode* headA=new ListNode(9);
    ListNode* root1=headA;
    for(int i=8;i>4;i--){
        headA->next=new ListNode(i);
        headA=headA->next;
    }
    ListNode* headB=new ListNode(7);
    ListNode* root2=headB;
    for(int i=6;i>5;i--){
        headB->next=new ListNode(i);
        headB=headB->next;
    }
    headB->next=headA;
    for(int i=4;i>=0;i--){
        headA->next=new ListNode(i);
        headA=headA->next;
    }
    Solution s;
    ListNode* answer;
    answer=s.getIntersectionNode(root1,root2);
    cout<<answer->val;
}