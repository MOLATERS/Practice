#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==nullptr)return nullptr;
    ListNode* a;
    ListNode* b;
    a=b=head;
    for(int i=0;i<k;i++){
        if(head==nullptr)return head;
        b=b->next;
    }
    ListNode* newhead=reverse(a,b);
    a->next=reverseKGroup(b,k);
    return newhead;
    }
    ListNode* reverse(ListNode* a,ListNode* b){
        ListNode* cur=a;
        ListNode* pre=nullptr;
        ListNode* nxt=a;
        while(cur!=b){
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        return pre;
    }
};