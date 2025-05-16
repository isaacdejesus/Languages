#include <bits/stdc++.h>

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

class linked_list_cycle_start{
    public:
        static list_node *find_cycle_start(list_node *head)
        {
            int cycle_length = 0;
            list_node *slow = head;
            list_node *fast = head;
            while(fast != nullptr && fast->next != nullptr)
            {
                fast = fast->next->next;
                slow = slow->next;
                if(slow == fast)  
                {
                    cycle_length = calc_cycle_length(slow);
                    break;
                }
            }
            return find_start(head, cycle_length);
        }
    private:
        static int calc_cycle_length(list_node *slow)
        {
            list_node *current = slow;
            int cycle_length = 0;
            do{
                current = current->next;
                cycle_length++;
            }
            while(current != slow);
            return cycle_length;
        }
        static list_node *find_start(list_node *head, int cycle_length)
        {
            list_node *pointer_1 = head;
            list_node *pointer_2 = head;
            while(cycle_length > 0)
            {
                pointer_2 = pointer_2->next;
                cycle_length--;
            }
            while(pointer_1 != pointer_2)
            {
                pointer_1 = pointer_1->next;
                pointer_2 = pointer_2->next;
            }
            return pointer_1;
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

    head->next->next->next->next->next->next = head->next->next;
    std::cout<<"list cycle start: "<<linked_list_cycle_start::find_cycle_start(head)->value<<'\n';

    head->next->next->next->next->next->next = head->next->next->next;
    std::cout<<"list cycle start: "<<linked_list_cycle_start::find_cycle_start(head)->value<<'\n';

    head->next->next->next->next->next->next = head;
    std::cout<<"list cycle start: "<<linked_list_cycle_start::find_cycle_start(head)->value<<'\n';
}
