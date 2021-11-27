#include <iostream>
#include "hash.h"

int main()
{
    hash<std::string> *hashString= new hash<std::string>(101);
    hashString->insert("Chicken");
    hashString->insert("ckenChi");
    hashString->insert("enckChi");
    hashString->insert("Cckenhi");
    hashString->insert("Potato");
    hashString->insert("Soup");
    hashString->display();
    return 0;
}