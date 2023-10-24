#include <iostream>
#include "linked_list.h"

int main()
{
    linked_list<int> *list = new linked_list<int>;
    list->insert_last(0);
    list->insert_last(2);
    list->insert_last(4);
    list->insert_last(6);
    list->insert_last(8);
    list->insert_last(10);
    list->delete_node(list->search(0));
    list->delete_node(list->search(4));
    list->delete_node(list->search(10));
    list->insert_first(0);
    list->insert_first(4);
    //list->insert_last(6);
    //list->insert_last(8);
    //list->insert_last(10);
    list->display();
    //node<int> *temp = list->search(6);
    //std::cout<<list->search(6)->info;
    //if(temp)  //check if null to avoid seg
        //std::cout<<temp->info;
    std::cout<<'\n';
    //std::cout<<"Number of items in list is: "<<list->get_length()<<'\n';
    return 0;
}
