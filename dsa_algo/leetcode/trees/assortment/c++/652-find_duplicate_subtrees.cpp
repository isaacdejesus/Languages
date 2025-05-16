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
    std::string preorder(TreeNode* node, std::unordered_map<std::string, std::vector<TreeNode*>>& sub_trees, std::vector<TreeNode*>& result)
    {
        if(node == nullptr)
            return "null";
        std::string res = to_string(node->val) + "," + preorder(node->left, sub_trees, result) + "," + preorder(node->right, sub_trees, result);
        if(sub_trees[res].size() == 1)
            result.push_back(node);
        std::vector<TreeNode*> temp = sub_trees[res];
        temp.push_back(node);
        std::cout<<temp.size()<<'\n';
        sub_trees[res] = temp;
        return res;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::unordered_map<std::string, std::vector<TreeNode*>> sub_trees;
        std::vector<TreeNode*> result;
        preorder(root, sub_trees, result);
        return result;

    }
};
