/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int i = 0, size = traversal.size();

        while (i < size) {
            int depth = 0, num = 0;
            while (traversal[i] == '-') {depth++; i++; }
            while (i < size && isdigit(traversal[i])) {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }
            TreeNode* node = new TreeNode(num);
            if (depth == st.size()) {
                if (!st.empty()) st.top()->left = node;
            }
            else {
                while (st.size() > depth) st.pop();
                st.top()->right = node;
            }
            st.push(node);
        }
        while (st.size() > 1) st.pop();
        return st.top();
    }
};
