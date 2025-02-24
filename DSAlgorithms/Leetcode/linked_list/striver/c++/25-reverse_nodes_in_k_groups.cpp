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
       if(k <= 1 || head == nullptr)  //if only 1 node, no need to reverse
            return head;
       ListNode* current = head;
       ListNode* prev = nullptr;
       while(true)
       {
            ListNode* last = prev;
            ListNode* new_end = current;
            ListNode* next = current->next;
            ListNode* temp = nullptr;
            int count = 0;
            temp = current;  //pointer to current node
            while(temp != nullptr )  //count node to the right of current
            {
                temp = temp->next;
                count++;  
            }           
            if(count < k)  //if < k nodes, means there are less than k nodes left on list. Done
                break;
            for(int i = 0; current!= nullptr && i < k ; i++)  //reverse k nodes
            {
                current->next = prev;
                prev = current;
                current = next;
                if(next != nullptr)
                    next = next->next;
            }
            if(last != nullptr)  //if nodes to the left, link left side to the newly reversed head
                last->next = prev;
            else
                head = prev;  //if no nodes to the left, newly reversed head is the new head
        
            new_end->next = current;  //link end of newly reversed list to next element on list/to the right
            if(current == nullptr)  //if current is null, reached end of list. Done
                break; 
            prev = new_end; //update prev to be end of newly reversed list
       }
        return head;
    }
};