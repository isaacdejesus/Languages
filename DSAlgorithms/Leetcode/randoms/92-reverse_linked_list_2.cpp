
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(left == right) 
            return head;
        ListNode* current = head;
        ListNode* prev = nullptr;
        for(int i = 0; current != nullptr && i < left - 1; i++)
        {
            prev = current;
            current = current->next;
        }
        ListNode* last = prev;
        ListNode* new_end = current;
        //reverse between left and right
        ListNode* next = current->next;
        for(int i = 0; current!= nullptr && i < right - left + 1; i++)
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
        return head;
    }
};