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
        ListNode* root1=headA;
        int sizeA=0;
        ListNode* root2=headB;
        int sizeB=0;
        while(root1){
            root1=root1->next;
            sizeA++;
        }
        while(root2){
            root2=root2->next;
            sizeB++;
        }
        root1=headA;
        root2=headB;
        if(sizeB>sizeA){
            for(int i=0;i<sizeB-sizeA;i++){
                root2=root2->next;
            }
        }
        else{
            for(int i=0;i<sizeA-sizeB;i++){
                root1=root1->next;
            }
        }
        while(root1!=nullptr&&root2!=nullptr&&root1!=root2){
            root1=root1->next;
            root2=root2->next;
        }
        if (root1==nullptr||root2==nullptr)return nullptr;
        else
        return root1;
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