/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       std::unordered_map<Node*, Node*> old_copy;
       Node* current = head;
       while(current != nullptr) 
       {
           Node* copy_node = new Node(current->val);
           old_copy[current] = copy_node;
           current = current->next;
       }
        current = head;
        while(current != nullptr)
        {
            Node* copy_node = old_copy[current];
            copy_node->next = old_copy[current->next];
            copy_node->random = old_copy[current->random];
            current = current->next;
        }
        return old_copy[head];
    }
};