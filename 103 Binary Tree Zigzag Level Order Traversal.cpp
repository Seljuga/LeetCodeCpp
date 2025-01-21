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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool isLeftRight = true;

        while(!q.empty()) {
            int size = q.size();
            vector<int> v(size);

            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                int index = isLeftRight ? i : size-i-1;
                v[index] = node->val;
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            isLeftRight = !isLeftRight;
            ans.push_back(v);
        }
        return ans;
    }
};
