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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        unordered_map<int, int> freq;
        while (curr) {
            freq[curr->val]++;
            curr = curr->next;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        curr = head;
        if (!head) return nullptr;

        while (curr) {
            if (freq[curr->val]>1) {
                prev->next = curr->next;
                delete curr;
            }
            else prev = curr;
            curr = prev->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
