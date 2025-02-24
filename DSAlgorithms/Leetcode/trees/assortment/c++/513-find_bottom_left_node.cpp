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
    int findBottomLeftValue(TreeNode* root) {
       std::queue<TreeNode*> q;
       q.push(root);
       TreeNode* node = nullptr;
       while(!q.empty())
       {
           node = q.front();
           q.pop();
           //add vals right to left so that last element is left most
           if(node->right != nullptr)
                q.push(node->right);
           if(node->left != nullptr)
                q.push(node->left);
       }
       return node->val;
    }
};
