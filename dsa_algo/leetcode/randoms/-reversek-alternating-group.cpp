//similar to #25 leetcode. Except alternade reversing depending on k
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* reverseKAlternateGroup(ListNode* head, int k) {
       if(k <= 1 || head == nullptr) 
            return head;
       ListNode* current = head;
       ListNode* prev = nullptr;
       while(current!= nullptr)
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
        std::cout<<"Count is: "<<count<< " k is: "<<k<<'\n';
        if(count < k)
        {
            std::cout<<"breaking for loop"<<'\n';
            break;
        }
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
        //skip k nodes after reversing k nodes
        for(int i = 0; current != nullptr && i < k; i++)
        {
            prev = current;
            current = current->next;
        }
       }
        return head;
    }
};