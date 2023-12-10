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
    int min_dif = INT_MAX;
    TreeNode* prev = nullptr;
    
    int minDiffInBST(TreeNode* root) {
       in_order(root);
       return min_dif;
    }
    void in_order(TreeNode* node)
    {
        if(node == nullptr)
            return;
        in_order(node->left);
        if(prev != nullptr)
            min_dif = std::min(min_dif, (node->val - prev->val));
        prev = node;
        in_order(node->right);
    }
};
