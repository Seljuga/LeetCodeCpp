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
    void traverseNode(TreeNode* root, int sum, vector<int>& data) {
        if (!root) return;
        sum *= 10;
        sum += root->val;
        if (!root->left && !root->right) data.push_back(sum);
        traverseNode(root->left, sum, data);
        traverseNode(root->right, sum, data);
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int> data;
        int ans = 0;
        if (!root) return 0;
        traverseNode(root, 0, data);
        for (auto n : data) ans += n;
        return ans;
    }
};
