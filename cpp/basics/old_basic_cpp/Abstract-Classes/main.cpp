#include<iostream>
#include "being.h"
#include "chicken.h"
#include <string>

int main()
{
    chicken<std::string> *chick=new chicken<std::string>("Rob", "Chicken");
    chick->display();

}