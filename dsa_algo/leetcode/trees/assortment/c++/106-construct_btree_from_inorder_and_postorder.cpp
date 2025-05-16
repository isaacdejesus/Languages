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
    std::unordered_map<int, int> inorder_indexes;  //maps val to index
    TreeNode* helper(int left, int right, vector<int>& postorder)
    {
        if(left > right)
            return nullptr;
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        int index = inorder_indexes[root->val];
        root->right = helper(index + 1, right, postorder);
        root->left = helper(left, index - 1, postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
            inorder_indexes[inorder[i]] = i;
        return helper(0, inorder.size() - 1, postorder);
    }
};
