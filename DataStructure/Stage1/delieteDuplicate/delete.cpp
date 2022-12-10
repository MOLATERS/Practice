#include <iostream>
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
    ListNode* deleteDuplicates(ListNode* head) {
    //     queue<ListNode*> Q;
        // if(head==nullptr||head->next==nullptr) return head;
    //     ListNode* pre=head;
    //     ListNode* temp=pre->next;
    //     ListNode* next;
    //     while(pre!=nullptr&&temp!=nullptr)
    //     {
    //         if(temp->val!=pre->val||pre==head)
    //         Q.push(pre);
    //         temp=pre;
    //         pre=pre->next;
    //     }
    //     Q.pop();temp=head;
    //     while(!Q.empty()){
    //         temp->next=Q.front();
    //         Q.pop();
    //         temp=temp->next;
    //     }
    //     temp->next=nullptr;
    //     return head;
    // }
        ListNode* sub=head;
        while(sub!=nullptr&&sub->next!=nullptr)
        {
            if(sub->val==sub->next->val)
            {
                sub->next=sub->next->next;
            }
            else
            {
                sub=sub->next;
            }
        }
        return head;
    }
};
main()
{
    ListNode* p_1=new ListNode(3);
    ListNode* p0=new ListNode(3,p_1);
    ListNode* p1=new ListNode(3,p0);
    ListNode* p2=new ListNode(1,p1);
    ListNode* p3=new ListNode(1,p2);
    Solution s;
    ListNode* head=s.deleteDuplicates(p3);
    while(head!=nullptr)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return 0;
}