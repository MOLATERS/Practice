#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 1. compare the first item to decide which would be the head,and save the father
        ListNode *head = list1->val > list2->val ? list2 : list1;
        // 2. have pointer father and son to move
        ListNode *father = head;
        ListNode *son = head == list1 ? list2 : list1;
        while (son != nullptr && father->next != nullptr)
        {
            // if father->next is bigger than the son
            if (son->val <= father->next->val)
            {
                ListNode *temp = son->next;
                son->next = father->next;
                father->next = son;
                son = temp;
            }
            // if father->next is smaller than the son
            if (son->val > father->next->val)
            {
                father = father->next;
            }
        }
        if (son != nullptr)
        {
            father->next = son;
        }
        return head;
    }
};
