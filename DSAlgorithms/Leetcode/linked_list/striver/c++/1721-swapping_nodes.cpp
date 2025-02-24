/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* current = head;
        for(int i = 0; i < k - 1; i++)    
            current = current->next;
        ListNode* left = current;
        ListNode* right = head;
        while(current->next != nullptr)
        {
            current = current->next;
            right = right->next;
        }
        int temp = left->val; 
        left->val = right->val;
        right->val = temp;
        return head;
    }
};