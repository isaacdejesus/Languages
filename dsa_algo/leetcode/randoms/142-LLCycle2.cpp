struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    int lengthCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                ListNode *temp = slow;
                int length = 0;
                do{
                    temp = temp->next;
                    length++;
                }
                while(temp != slow);
                return length;
            }
        }
        return 0;
    }
    ListNode *detectCycle(ListNode *head) {
       int length = 0;
       ListNode * fast = head;
       ListNode *slow = head;
       while(fast != nullptr && fast->next != nullptr) 
       {
           fast = fast->next->next;
           slow = slow->next;
           if(fast == slow)
           {
               length = lengthCycle(slow);
               break;
           }
       }
       if(length == 0)
        return nullptr;
       ListNode *first = head;
       ListNode *second = head;
       while(length > 0)
       {
           second = second->next;
           length--;
       }
       while(first != second)
       {
           first = first->next;
           second = second->next;
       }
    return second;
    }
};