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
class BSTIterator {
public:
    std::stack<TreeNode*> a_stack;
    BSTIterator(TreeNode* root) {
        while(root != nullptr)
        {
            a_stack.push(root);
            root = root->left;
        }
    }
    
    int next() {
       TreeNode* result = a_stack.top();
       a_stack.pop();
        TreeNode* current = result->right;
       while(current != nullptr)
       {
           a_stack.push(current);
           current = current->left;
       }
       return result->val;
    }
    
    bool hasNext() {
        return !a_stack.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */