#include <iostream>
#include "personTemplate.h"
#include <string>

int main()
{
	//declaring a regular object template
	personTemplate<std::string, int> person;
	person.setFirstName("isaac");
	person.setLastName("The forgotten");
	person.setAge(9);
	person.displayPersonInfo();

	//declaring object template as pointer
	personTemplate<std::string, int> *personPointer= new personTemplate<std::string, int>;
	personPointer->setFirstName("Teresa");
	personPointer->setLastName("Timeless");
	personPointer->setAge(23);
	personPointer->displayPersonInfo();

	//declaring object template as pointer with overloaded constructor
	personTemplate<std::string, int> *personPointerLoaded= new personTemplate<std::string, int> ("Viewtiful", "Joe", 27);
	personPointerLoaded->displayPersonInfo();
}
