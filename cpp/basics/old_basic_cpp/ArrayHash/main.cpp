#include <iostream>
#include "arrayHash.h"

int main()
{
    arrayHash<std::string> *stringHash=new arrayHash<std::string>(111);
    stringHash->linearProbe("Chicken");
    stringHash->linearProbe("Potato");
    stringHash->linearProbe("Soup");
    stringHash->linearProbe("Sopu");
    stringHash->linearProbe("Potota");
    stringHash->linearProbe("Ckenchi");
    stringHash->linearProbe("Supo");
    stringHash->linearProbe("nekcihC");
    stringHash->linearProbe("ckhienC");
    stringHash->linearProbe("Soooup");
    stringHash->linearProbe("Suooop");
    stringHash->linearProbe("zxcv111111");
    stringHash->linearProbe("1zxcv11111");
    stringHash->linearProbe("pootaatoo");
    stringHash->linearProbe("taapootoo");
    stringHash->linearProbe("Pottoa");
    stringHash->linearProbe("ttooap");
    stringHash->linearProbe("pttooa");
    stringHash->linearProbe("potato");
    stringHash->linearProbe("pttooa");
    stringHash->linearProbe("ooaptt");
    stringHash->linearProbe("ttoaop");
    stringHash->remove("ttoaop");
    stringHash->remove("potato");
    stringHash->remove("ooaptt");
    stringHash->display();
    std::cout<<stringHash->search("ttooap");
    return 0;
}