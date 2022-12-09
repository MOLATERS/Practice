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
    bool hasCycle(ListNode *head) {
        bool answer=false;
        int flag=0;
        ListNode* temp;
        temp=head;
        vector<ListNode*> list;
        while(temp!=nullptr)
        {
            for(int i=0;i<list.size();i++)
            if(temp->next==list[i]->next&&temp->val==list[i]->val)
            {
                answer=true;
                return answer;
            }
            if(!answer){
                list.push_back(temp);
                temp=temp->next;
            }
        }
        return answer;

    }
};