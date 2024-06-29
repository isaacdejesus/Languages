#include<bits/stdc++.h>
class list_node {
    public: 
        int value = 0;
        list_node *next;
        list_node(int value)
        {
            this->value = value;
            next = nullptr;
        }
};

class linked_list_cycle {
    public:
        static bool has_cycle(list_node *head)
        {
            list_node *slow = head;
            list_node *fast = head;
            while(fast != nullptr && fast->next != nullptr)
            {
                fast = fast->next->next;
                slow = slow->next;
                if(slow == fast)
                    return true;
            }
            return false;
        }
};

int main(int argc, char *argv[])
{
    list_node *head = new list_node(1);
    head->next = new list_node(2);
    head->next->next = new list_node(3);
    head->next->next->next = new list_node(4);
    head->next->next->next->next = new list_node(5);
    head->next->next->next->next->next = new list_node(6);
    std::cout<<"list has cycle: " <<linked_list_cycle::has_cycle(head)<<'\n';

    head->next->next->next->next->next->next = head->next->next;
    std::cout<<"list has cycle: " <<linked_list_cycle::has_cycle(head)<<'\n';
    head->next->next->next->next->next->next = head->next->next->next;
    std::cout<<"list has cycle: " <<linked_list_cycle::has_cycle(head)<<'\n';
}
