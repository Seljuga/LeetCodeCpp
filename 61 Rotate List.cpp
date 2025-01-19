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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* cnt = head;
        int ct = 1;
        while (cnt->next) {
            cnt = cnt->next;
            ct++;
        }
        k = k % ct;
        if (k == 0) return head;
        ListNode* temp = head;
        ListNode* bond = temp;
        int a = ct - k;
        while (a--) {
            if (temp->next == NULL) {
                temp = head;
                continue;
            }
            bond = temp;
            temp = temp->next;
        }
        bond->next = NULL;
        ListNode* ans = temp;
        while (temp->next != NULL) temp = temp->next;
        temp->next = head;
        return ans;
    }
};
