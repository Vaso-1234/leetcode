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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* frontK = nullptr;

        for (int i = 1; i < k; i++)
            first = first->next;

        frontK = first;

        while (first->next) {
            first = first->next;
            second = second->next;
        }

        swap(frontK->val, second->val);

        return head;
    }
};
