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
        ListNode* dum = new ListNode(0, head);  //node to always point to head. Used to start looping from head
        ListNode* current = head->next; //start w 2nd node bc 1st node is already sorted
        ListNode* prev = head; //points to first node
        ListNode* temp; //used to loop from head to find insert loc for current node
        while(current != nullptr)
        {
            if(current->val >= prev->val) //advance as long as current >= prev
            {
                prev = current;
                current = current->next;
                continue;
            }
            temp = dum;  //set temp to head
            while(current->val > temp->next->val) //loop to find insert loc for current
                temp = temp->next;
            prev->next =  current->next;  //insert current at temp loc
            current->next = temp->next;
            temp->next = current;
            current = prev->next;
        }
        return dum->next;
    }
};