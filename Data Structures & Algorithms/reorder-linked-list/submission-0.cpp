/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr)
    {
        ListNode *nextTmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTmp;
    }
    return prev;
}

void reorderList(ListNode *head)
{

    if (!head || !head->next)
    {
        return;
    }

    // use fast and slow pointer to find midpoint
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow now points to midpoint.
    ListNode *curr = head;
    ListNode         *secondHalf = slow->next;
     secondHalf = reverseList(secondHalf);
    slow->next = nullptr;
    while (secondHalf)
    {

        ListNode *tmp1 = curr->next;
        ListNode *tmp2 = secondHalf->next;

        curr->next = secondHalf;
        secondHalf->next = tmp1;

        curr = tmp1;
        secondHalf = tmp2;
    }
}
};
