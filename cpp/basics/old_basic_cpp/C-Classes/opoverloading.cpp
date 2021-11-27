#include<iostream>
#include "opoverloading.h"
int main()
{
    opoverloading<int> *personOne= new opoverloading<int>(1000);
    opoverloading<int> *personTwo= new opoverloading<int>(3300);
    opoverloading<int> totalIncome= *personOne+*personTwo;
    totalIncome.display();

}