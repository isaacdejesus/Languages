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
    int getTreeDepth(TreeNode* node)
    {
        if(!node)
            return 0;
        return 1 + std::max(getTreeDepth(node->left), getTreeDepth(node->right));
    }
    bool isBalanced(TreeNode* root) {
       if(!root) 
           return true;
        int leftDepth = getTreeDepth(root->left);
        int rightDepth = getTreeDepth(root->right);
        return std::abs(leftDepth - rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
