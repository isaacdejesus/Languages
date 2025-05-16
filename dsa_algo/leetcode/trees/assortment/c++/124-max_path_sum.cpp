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
    int dfs(TreeNode* root, int& max_path)
    {
        if(root == nullptr)
            return 0;
        int left = std::max(dfs(root->left, max_path), 0);
        int right = std::max(dfs(root->right, max_path), 0);
        int current_path = root->val + left + right;
        max_path = std::max(max_path, current_path);
        return root->val + std::max(left, right);

    }
    int maxPathSum(TreeNode* root) {
       int max_path = INT_MIN;
       dfs(root, max_path);
       return max_path;
    }
};