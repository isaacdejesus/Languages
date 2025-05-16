#include<bits/stdc++.h>
class list_node{
    public:
        int value = 0;
        list_node *next;
        list_node(int value)
        {
            this->value = value;
            next = nullptr;
        }
};

class rearrange_list {
    public:
        static void reorder(list_node *head)
        {
            if(head == nullptr || head->next == nullptr)
                return;
            list_node *slow = head;
            list_node *fast = head;
            while(fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            list_node *head_second_half = reverse(slow);
            list_node *head_first_half = head;
            while(head_first_half != nullptr && head_second_half != nullptr)
            {
                list_node *temp = head_first_half->next;
                head_first_half->next = head_second_half;
                head_first_half = temp;
                temp = head_second_half->next;
                head_second_half->next = head_first_half;
                head_second_half = temp;
            }
            if(head_first_half != nullptr)
                head_first_half->next = nullptr;
        }
    private:
        static list_node *reverse(list_node *head)
        {
            list_node *prev = nullptr;
            while(head != nullptr)
            {
                list_node *next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }
            return prev;
        }
};

int main(int argc, char *argv[])
{
    list_node *head = new list_node(2);
    head->next = new list_node(4);
    head->next->next = new list_node(6);
    head->next->next->next = new list_node(8);
    head->next->next->next->next = new list_node(10);
    head->next->next->next->next->next = new list_node(12);
    rearrange_list::reorder(head);
    while(head != nullptr)
    {
        std::cout<<head->value<<" ";
        head = head->next;
    }
}
