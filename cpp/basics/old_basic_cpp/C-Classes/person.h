#include <iostream>
#include <string>

/* 
Declares a class named person
Private variables can be accessed by all functions within the class but not outside
Public functions are the onlyones accessible to the user
*/
class person
{
    private:
        std::string firstName;
        std::string lastName;
        int age;

    public:
        person();
	    person(std::string firstNameIn, std::string lastNameIn, int ageIn);
	    void setFirstName(std::string firstNameIn);
	    void setLastName(std::string lastNameIn);
	    void setAge(int ageIn);
	    void displayPersonInfo();
};

//Class implementation
//default constructor sets all parameters to null
person::person()
{	firstName="";
	lastName="";
	age=0;
}
//overloaded contructor allows user to set values during declaration
person::person(std::string firstNameIn, std::string lastNameIn, int ageIn)
{
	firstName=firstNameIn;
	lastName=lastNameIn;
	age=ageIn;
}

void person::setFirstName(std::string firstNameIn)
{
	firstName=firstNameIn;
}

void person::setLastName(std::string lastNameIn)
{
	lastName=lastNameIn;
}

void person::setAge(int ageIn)
{
	age=ageIn;
}

void person::displayPersonInfo()
{
	std::cout<<"Name: "<<firstName<<" "<<lastName<<'\n';
	std::cout<<"Age: "<<age<<'\n';
}

