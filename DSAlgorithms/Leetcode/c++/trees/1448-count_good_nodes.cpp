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
    int dfs(TreeNode* node, int max_val)
    {
        if(node == nullptr)
            return 0;
        int res = 0;
        if(node->val >= max_val)
            res = 1;
        max_val = std::max(max_val, node->val);
        res += dfs(node->left, max_val);
        res += dfs(node->right, max_val);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
