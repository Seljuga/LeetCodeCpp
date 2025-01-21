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
private:
    int dfs(vector<vector<int>> &ans, int l, TreeNode* root) {
        if (root == NULL) return 0;
        if (ans.size() == l) {
            vector<int> tmp;
            ans.push_back(tmp);
        }
        ans[l].push_back(root->val);
        dfs(ans, l+1, root->left);
        dfs(ans, l+1, root->right);
        return 0;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(ans, 0, root);
        return ans;
    }
};
