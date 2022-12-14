#include <iostream>
#include <vector>
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
    ListNode* middleNode(ListNode* head) {
        ListNode* point1=head;
        ListNode* point2=head;
        if(!head)return nullptr;
        if(!head->next)return head;
        if(!head->next->next) return head->next;
        while(point1&&point1->next){
            point1=point1->next->next;
            point2=point2->next;
        } 
        return point2;
    }
};
main(){
    ListNode* temp=new ListNode(1);
    ListNode* head=temp;
    for(int i=0;i<4;i++){
        temp->next=new ListNode(i+2);
        temp=temp->next;
    }
    Solution s;
    ListNode* answer;
    answer=s.middleNode(head);
    while(answer){
        cout<<answer->val<<" ";
        answer=answer->next;
    }
    return 0;
}