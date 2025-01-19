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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int s, int e, int &i) {
        if (s > e) return nullptr;
        int value = postorder[i];
        TreeNode* temp = new TreeNode(value);
        i--;

        int pos = -1;
        for (int j=s; j <= e; j++) {
            if (inorder[j] == value) {
                pos = j;
                break;
            }
        }
        temp->right = solve(inorder, postorder, pos + 1, e, i);
        temp->left = solve(inorder, postorder, s, pos - 1, i);
        return temp;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;
        int i = postorder.size() - 1;
        return solve(inorder, postorder, 0, inorder.size() - 1, i);
    }
};
