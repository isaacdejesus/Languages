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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if(root != nullptr) 
        {
            std::vector<int> left = inorderTraversal(root->left);
            std::vector<int> right = inorderTraversal(root->right);
            for(auto node: left)
                result.push_back(node);
            result.push_back(root->val);
            for(auto node: right)
                result.push_back(node);
        }
        return result;
    }
};
