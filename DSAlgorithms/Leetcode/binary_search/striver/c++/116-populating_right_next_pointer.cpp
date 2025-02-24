/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* current = root;
        Node* next = nullptr;
        if(root)
            next = root->left;
        while(current && next)
        {
            current->left->next = current->right;
            if(current->next != nullptr)
                current->right->next = current->next->left;
            current = current->next;
            if(!current)
            {
                current = next;
                next = current->left;
            }
        }
        return root;
    }
};