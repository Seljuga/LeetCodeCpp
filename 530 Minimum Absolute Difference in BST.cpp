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
    vector<int> vec;
    void binary_search(TreeNode* root) {
        if (root == NULL) return ;
        binary_search(root->left);
        vec.push_back(root->val);
        binary_search(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        binary_search(root);
        int ans = 2e9 + 7, size = vec.size();
        for (int i=1; i<size; i++) ans = min(ans, vec[i]-vec[i-1]);
        return ans;
    }
};
