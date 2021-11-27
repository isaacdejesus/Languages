#include <iostream>
#include <string>
#include "studentTemplate.h"
//#include "personTemplate.h"

int main()
{

    studentTemplate< std::string, int> *personOne= new studentTemplate<std::string, int>("Isaac", "Reyes", 27, "Computer Science", "n/a", 2020);
    personOne->setFirstName("isaac");
    personOne->displayStudentInfo();
}