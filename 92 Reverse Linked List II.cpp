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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temphead = head;
        int i=1;
        ListNode* leftLast = NULL;
        while (i<left) {
            leftLast = head;
            head = head->next;
            i++;
        }
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (i <= right && temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            i++;
        }
        head->next = temp;
        if (leftLast == NULL) return prev;
        else leftLast->next = prev;
        return temphead;
    }
};
