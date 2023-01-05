#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)return nullptr;
        ListNode* fast=head;
        ListNode* slow=head;
        do{
            if(fast->next==nullptr)break;
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=slow&&fast!=nullptr&&slow!=nullptr);
        if(!fast||!fast->next)return nullptr;
        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};
int main(){
    ListNode* head=new ListNode(1);
    // ListNode* nod1=new ListNode(2);
    // head->next=nod1;
    // ListNode* nod2=new ListNode(3);
    // nod1->next=nod2;
    // ListNode* nod3=new ListNode(4);
    // nod2->next=nod3;
    // nod3->next=nod1;
    Solution S;
    ListNode* answer;
    answer=S.detectCycle(head);
    if(answer)
    cout<<answer->val;
}