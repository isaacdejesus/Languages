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
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(k <= 1 || head == nullptr) 
            return head;
       ListNode* current = head;
       ListNode* prev = nullptr;
       while(true)
       {
            ListNode* last = prev;
            ListNode* new_end = current;
            //reverse between left and right
            ListNode* next = current->next;
            ListNode* temp = nullptr;
            int count = 0;
            temp = current;
            while(temp != nullptr ) 
            {
                temp = temp->next;
                count++;  
            }           
            if(count < k)
                break;
            for(int i = 0; current!= nullptr && i < k ; i++)
            {
                current->next = prev;
                prev = current;
                current = next;
                if(next != nullptr)
                    next = next->next;
            }
            if(last != nullptr)
                last->next = prev;
            else
                head = prev;
        
            new_end->next = current;
            if(current == nullptr)
                break; 
            prev = new_end;
       }
        return head;
    }
};