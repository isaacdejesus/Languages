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
    std::pair<int, int> dfs(TreeNode* root)
    {
        if(root == nullptr)
        {
            std::pair<int, int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }
        std::pair<int, int> left_pair = dfs(root->left);
        std::pair<int, int> right_pair = dfs(root->right);
        int max_left = left_pair.first;
        int max_right = right_pair.first;
        int including_root = root->val + left_pair.second + right_pair.second;
        if(left_pair.second > left_pair.first)
            max_left = left_pair.second;
        if(right_pair.second > right_pair.first)
            max_right = right_pair.second;
        int excluding_root = max_left + max_right;
        std::pair<int, int> current_res;
        current_res.first = including_root;
        current_res.second = excluding_root;
        return current_res;
    }
    int rob(TreeNode* root) {
        std::pair<int, int> result_pair = dfs(root);
        if(result_pair.first > result_pair.second)
            return result_pair.first;
        else 
            return result_pair.second;
    }
};
