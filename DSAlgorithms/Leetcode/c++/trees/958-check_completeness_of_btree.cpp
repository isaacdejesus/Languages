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
    bool isCompleteTree(TreeNode* root) {
       std::queue<TreeNode*> q;
       q.push(root);
       while(!q.empty())
       {
           TreeNode* current = q.front();
           q.pop(); 
           if(current != nullptr)
           {
                q.push(current->left);
                q.push(current->right);
           }
           else
           {
               while(!q.empty())
                {
                    TreeNode* temp = q.front();
                    q.pop();
                    if(temp != nullptr)
                        return false;
                }
           }
       }
       return true;
    }
};
