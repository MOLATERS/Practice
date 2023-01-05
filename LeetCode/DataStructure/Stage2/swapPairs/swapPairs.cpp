#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=head;
        ListNode* pre=nullptr;
        while(temp!=nullptr&&temp->next!=nullptr){
            pre=swap(pre,temp,head);
            temp=pre->next;
        }
        return head;
    }
    ListNode* swap(ListNode* pre,ListNode* node,ListNode* &head){
        ListNode* temp=node->next->next;
        ListNode* temp2=node;
        node=node->next;
        node->next=temp2;
        node->next->next=temp;
        if(pre!=nullptr)pre->next=node;
        else
        head=node;
        return node->next;
    }
};
int main(){
    ListNode* headA=new ListNode(0);
    ListNode* root1=headA;
    for(int i=9;i>4;i--){
        headA->next=new ListNode(i);
        headA=headA->next;
    }
    Solution s;
    s.swapPairs(root1);
    return 0;
}