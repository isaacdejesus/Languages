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
    std::vector<TreeNode*> generate(int left, int right)
    {
        if(left == right)
        {
            std::vector<TreeNode*> res;
            TreeNode* node = new TreeNode(left);
            res.push_back(node);
            return res;
        }
        if(left > right)
        {
            std::vector<TreeNode*> res;
            res.push_back(nullptr);
            return res;
        }
        std::vector<TreeNode*> res;
        for(int val = left; val < right + 1; val++ )
        {
            std::vector<TreeNode*> l_trees = generate(left, val -1);
            for(int left_tree = 0; left_tree < l_trees.size(); left_tree++)
            {
                std::vector<TreeNode*> r_trees = generate(val + 1, right);
                for(int right_tree = 0; right_tree < r_trees.size(); right_tree++) 
                {
                    TreeNode* root = new TreeNode(val, l_trees[left_tree], r_trees[right_tree]);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
       return generate(1, n);
    }
};
