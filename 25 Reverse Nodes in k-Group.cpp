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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* node = dummy;
        ListNode* curr = head;
        stack<ListNode*> st;
        while (curr != NULL) {
            ListNode* s = curr;
            int cnt = 0;
            while (curr != NULL && cnt < k) {
                st.push(curr);
                curr = curr->next;
                cnt++;
            }
            if (cnt == k) {
                while (!st.empty()) {
                    node->next = st.top();
                    st.pop();
                    node = node->next;
                }
                node->next = curr;
            }
            else node->next = s;
        }
        return dummy->next;
    }
};
