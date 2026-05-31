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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (!head)
    {
        return nullptr;
    }

    // two pass approach.
    // first pass: Calculate the length of the list. O(n)

    int len{1};
    ListNode *prev{nullptr};
    ListNode *curr = head;

    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
        len++;
    }

    // second pass: remove x = (len - n)th node. O(n)
    int x = len - n;
    if (x == 0){
        return head->next;
    }

    {
        ListNode *prev{nullptr};
        ListNode *curr = head;
        while (x > 0)
        {
            prev = curr;
            curr = curr->next;
            --x;
        }

        prev->next = curr->next;
        curr->next = nullptr;
    }

    return head;
    }
};
