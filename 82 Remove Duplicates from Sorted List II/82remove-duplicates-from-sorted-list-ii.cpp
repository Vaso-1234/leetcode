/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (head) {

            if (head->next && head->val == head->next->val) {

                int val = head->val;

                while (head && head->val == val) {
                    head = head->next;
                }

                prev->next = head;
            }
            else {
                prev = head;
                head = head->next;
            }
        }

        return dummy->next;
    }
};