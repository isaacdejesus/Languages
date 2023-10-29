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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        int carry = 0;
        while(l1 || l2)
        {
            int val1 = 0;
            int val2 = 0;
            int node_sum = 0;
            if(l1 != nullptr) //if value is missing, it is set to 0
                val1 = l1->val;
            if(l2 != nullptr)  //if node exists, use node's value
                val2 = l2->val;
            //new digit
            node_sum = val1 + val2 + carry;
            carry = node_sum / 10; //remove the last digit
            node_sum = node_sum % 10;  //get remainder/last digit
            ListNode* new_node = new ListNode(node_sum);
            current->next = new_node;
            current = current->next;

            if(l1 != nullptr)
                l1 = l1->next;
            if(l2 != nullptr)
                l2 = l2->next;
        }
        if(carry == 1) // add carry at end of list if any carry left after loop breaks
            current->next = new ListNode(1);
        return dummy->next;
    }
};