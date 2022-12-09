#include <iostream>
#include "linked_list.h"

int main()
{
    linked_list<int> *list = new linked_list<int>;
    list->insert_first(0);
    list->insert_first(1);
    list->insert_first(2);
    list->display();
    std::cout<<"Number of items in list is: "<<list->get_length()<<'\n';
    return 0;
}