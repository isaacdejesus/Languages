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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) 
            return head;
        ListNode* dum = new ListNode(0, head);
        ListNode* current = head->next;
        ListNode* prev = head;
        ListNode* temp;
        while(current != nullptr)
        {
            if(current->val >= prev->val)
            {
                prev = current;
                current = current->next;
                continue;
            }
            temp = dum;
            while(current->val > temp->next->val)
                temp = temp->next;
            prev->next =  current->next;
            current->next = temp->next;
            temp->next = current;
            current = prev->next;
        }
        return dum->next;
    }
};