#include <iostream>
#include "linked_list.h"

int main()
{
    linked_list<int> *list = new linked_list<int>;
    list->insert_last(0);
    list->insert_last(1);
    list->insert_last(2);
    list->insert_last(3);
    list->insert_at_index(9, 2);
    list->delete_at_index(1);
    list->display();
    std::cout<<"Number of items in list is: "<<list->get_length()<<'\n';
    return 0;
}
