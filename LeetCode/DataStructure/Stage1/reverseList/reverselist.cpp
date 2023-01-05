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
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         stack<ListNode*> stk;
//         ListNode* p=head;
//         while(p!=nullptr){
//             stk.push(p);
//             p=p->next;
//         } 
//         if(!stk.empty()){
//         ListNode* head_new=stk.top();
//         stk.pop();
//         p=head_new;
//         while(!stk.empty()){
//             p->next=stk.top();
//             stk.pop();
//             p=p->next;
//         }
//         p->next=nullptr;
//         return head_new;
//         }
//         else
//         return head;
//     }
// };//�ǵݹ鷽ʽ
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=nullptr;
        ListNode* prev=head;
        while(prev){
            ListNode* temp=prev->next;
            prev->next=curr;
            curr=prev;
            prev=temp;
        }
        return curr;
    }
};