#include <iostream>
#include "singlelinkedlist.h"
#include <string>

int main()
{
    // singlelinkedlist<std::string> *listOfStrings= new singlelinkedlist<std::string>;
    // listOfStrings->addAtBeginning("soup");
    // listOfStrings->addAtBeginning("potato");
    // listOfStrings->addAtBeginning("chicken");
    // listOfStrings->display();

    singlelinkedlist<int> *listOfNums=new singlelinkedlist<int>;
    listOfNums->addAtEnd(9);
    listOfNums->addAtEnd(6);
    listOfNums->addAtEnd(16);
    listOfNums->addAtEnd(11);
    listOfNums->addAtEnd(69);
    listOfNums->addAfterIndex(999,3); //good
    listOfNums->addAfterIndex(7777, 5);
    std::cout<<(listOfNums->search(7777))<<'\n';
    listOfNums->addInOrder(1);
    listOfNums->addInOrder(999999);
    listOfNums->display();
    std::cout<<"Testing the print info at node function"<<"\n";
    listOfNums->printInfoAtNode(listOfNums->objectAtIndex(8));
    std::cout<<"testing swap function"<<'\n';
    //listOfNums->swapInfo(listOfNums->objectAtIndex(1), listOfNums->objectAtIndex(4));
    listOfNums->bubbleSort();
    listOfNums->display();
    return 0;
}
