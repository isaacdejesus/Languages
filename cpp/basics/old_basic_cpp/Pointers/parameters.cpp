#include <iostream>
#include <string>

//function takes in 3 pointers. Third pointer is passed by reference
//Function returns a new string composed of input strings

std::string *pointerReturn(std::string *pointer1, std::string *pointer2, std::string *&pointer3);
int main()
{
    //declare dynamic vars
    std::string *namePointer=new std::string;
    std::string *nicknamePointer=new std::string;
    std::string *returnPointer=new std::string;

    std::cout<<"Enter your name: "<<'\n';
    std::cin>>*namePointer;
    std::cout<<'\n';
    std::cout<<"Enter your nickname: "<<'\n';
    std::cin>>*nicknamePointer;

    pointerReturn(namePointer, nicknamePointer, returnPointer);

    std::cout<<*returnPointer;
    return 0;
}

std::string *pointerReturn(std::string *pointer1, std::string *pointer2, std::string *&pointer3)
{
    *pointer3=*pointer1+" The "+*pointer2;
    return pointer3;
}