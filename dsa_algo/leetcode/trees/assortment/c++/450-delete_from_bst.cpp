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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return root;
        if(key > root->val) 
            root->right = deleteNode(root->right, key);
        else if(key < root->val)
            root->left = deleteNode(root->left, key);
        else  //found node to be deleted
        {
            if (root->left == nullptr)  //if no children, will replace node with nullptr
                return root->right;
            else if(root->right == nullptr)  //if one child, will replace node with this child
                return root->left;
            //node has 2 children, find min val in right sub tree
            TreeNode* current = root->right;
            while(current->left != nullptr)
                current = current->left;
            root->val = current->val;  //replace node with min val in right subtree
            root->right = deleteNode(root->right, root->val);  //rec right subtree to delete duplicate val
        }
        return root;
    }
};
