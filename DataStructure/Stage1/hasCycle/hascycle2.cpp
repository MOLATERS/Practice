#include <iostream>
#include <unordered_map>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        unordered_map <ListNode*,int> hash;
        while(temp!=nullptr){
            if(hash[temp]==1)return true;
            hash[temp]++;
            temp=temp->next;
        }
        return false;
    }
};