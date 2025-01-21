/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp1 = head;
        Node* dummy = new Node(-1);
        Node* temp2 = dummy;
        while (temp1) {
            temp2->next = new Node(temp1->val);
            mp[temp1] = temp2->next;
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        Node* headCopy = dummy->next;
        delete dummy;
        temp1 = head;
        temp2 = headCopy;
        while (temp1) {
            temp2->random = mp[temp1->random];
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        return headCopy;
    }
};
