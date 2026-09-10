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

#include <queue>
using namespace std;

class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        for (auto node : lists) {
            if (node)
                minHeap.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();

            tail->next = top;
            tail = tail->next;

            if (top->next)
                minHeap.push(top->next);
        }

        return dummy->next;
    }
};
