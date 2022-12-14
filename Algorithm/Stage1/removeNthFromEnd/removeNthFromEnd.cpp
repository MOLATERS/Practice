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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        stack<ListNode*> stk;
        while(temp){
            stk.push(temp);
            temp=temp->next;
        }
        if(n==1){
            stk.pop();
            if(!stk.empty()){
                temp=stk.top();
                temp->next=nullptr;
            }
            else return nullptr;
        }
        else if(n==stk.size()){
            return head->next;
        }
        else if(n>stk.size()){
            return head;
        }
        else{
            ListNode* point1;
            ListNode* point2;
            for(int i=0;i<n;i++){
                if(i==n-2)
                point1=stk.top();
                stk.pop();
            }
            point2=stk.top();
            point2->next=point1;
        }
        return head;
    }
};
main(){
    ListNode* temp=new ListNode(1);
    ListNode* head=temp;
    Solution s;
    ListNode* answer=head;
    while(answer){
        cout<<answer->val<<" ";
        answer=answer->next;
    }
    cout<<endl;
    answer=s.removeNthFromEnd(head,1);
    while(answer){
        cout<<answer->val<<" ";
        answer=answer->next;
    }
    return 0;
}