#include <iostream>
#include "linked_list.h"

int main()
{
    linked_list<int> *list = new linked_list<int>;
    list->insert_last(1);
    list->insert_last(1);
    list->insert_last(1);
    list->insert_last(2);
    list->insert_last(3);
    list->insert_last(3);
    list->remove_duplicates();
    list->display();
    std::cout<<"Number of items in list is: "<<list->get_length()<<'\n';
    return 0;
}
