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
    ListNode* partition(ListNode* head, int x) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevFast = nullptr;

        while (fast) {
            if (fast->val < x && fast != slow) {
                ListNode* tmp = prevFast;
                prevFast->next = fast->next;
                if (slow == head && slow->val >= x) {
                    fast->next = head;
                    slow = head = fast;
                }
                else {
                    fast->next = slow->next;
                    slow->next = fast;
                }
                fast = tmp;
            }
            prevFast = fast;
            fast = fast->next;
            if (slow->next && slow->next->val < x && slow->val < x) slow = slow->next;
        }
        return head;
    }
};
