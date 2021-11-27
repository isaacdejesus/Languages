#include <iostream>
#include "person.h"
#include <string>

int main()
{
	//There are two ways to declare and access objects
	//First way
	//declaring an object of type person using default constructor
	person defaultPerson;
	//declaring an object of type person using overloaded constructor
	person overloadedPerson("isaac", "Cpt. Anemia", 26);
	//calling the display function to display info.
	overloadedPerson.displayPersonInfo();

	//To access the member functions of an object the "." operator is used
	defaultPerson.setFirstName("Teresa");
	defaultPerson.setLastName("Timeless");
	defaultPerson.setAge(23);
	//display function
	defaultPerson.displayPersonInfo();

	//second way of declaring and accessing objects is through pointers
	person *pointerPerson= new person;
	//The member functions are accessed using ->
	pointerPerson->setFirstName("Viewtiful");
	pointerPerson->setLastName("Joe");
	pointerPerson->setAge(21);
	pointerPerson->displayPersonInfo();

}
