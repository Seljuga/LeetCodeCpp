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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ret;
        queue<TreeNode*> qu;
        qu.push(root);
        while(qu.size() != 0) {
            size_t size = qu.size();
            for (int i=0; i<size; i++) {
                TreeNode* tmp = qu.front();
                if (i==size-1) ret.push_back(tmp->val);
                qu.pop();
                if (tmp->left) qu.push(tmp->left);
                if (tmp->right) qu.push(tmp->right);
            }
        }
        return ret;
    }
};
