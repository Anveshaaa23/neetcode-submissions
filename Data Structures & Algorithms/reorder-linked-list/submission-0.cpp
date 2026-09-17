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
    void reorderList(ListNode* head) {

    if (head == NULL || head->next == NULL)
        return;

    ListNode* first = head;

    while (first->next != NULL && first->next->next != NULL) {

        // find last node
        ListNode* prev = first;
        ListNode* last = first->next;

        while (last->next != NULL) {
            prev = last;
            last = last->next;
        }

        // remove last
        prev->next = NULL;

        // insert last after first
        last->next = first->next;
        first->next = last;

        // move first forward
        first = first->next->next;
    }
}
};
