#include <iostream>
#include "personTemplate.h"
#include <string>

template <class DataType1, class DataType2>
class studentTemplate : public personTemplate<DataType1, DataType2>
{
	private:
		DataType1 major;
		DataType1 minor;
		DataType2 graduationYear;
	
	public:
		studentTemplate(DataType1 firstName="", DataType1 lastName="", DataType2 age=0, DataType1 major="", DataType1 minor="", DataType2 graduationYear=0);
		void setMajor(DataType1 major);
		void setMinor(DataType1 minor);
		void setYear(DataType2 graduationYear);
		void displayStudentInfo();
};

template <class DataType1, class DataType2>
studentTemplate<DataType1, DataType2>::studentTemplate(DataType1 firstName, DataType1 lastName, DataType2 age, DataType1 major, DataType1 minor, DataType2 graduationYear):personTemplate<DataType1, DataType2>(firstName, lastName, age)
{
	//constructor calls base constructor to initialize the object
	//this->firstName=firstName;
	//this->lastName=lastName;
	this->age=age;
	this->major=major;
	this->minor=minor;
	this->graduationYear=graduationYear;
}

template <class DataType1, class DataType2>
void studentTemplate<DataType1, DataType2>::setMajor(DataType1 major)
{
	this->major=major;
}

template <class DataType1 , class DataType2>
void studentTemplate<DataType1, DataType2>::setMinor(DataType1 minor)
{
	this->minor=minor;
}

template <class DataType1, class DataType2>
void studentTemplate<DataType1, DataType2>::setYear(DataType2 graduationYear)
{
	this->graduationYear=graduationYear;
}

template<class DataType1, class DataType2>
void studentTemplate <DataType1, DataType2>::displayStudentInfo()
{
	this->displayPersonInfo();
	std::cout<<"Major: "<<major<<'\n';
	std::cout<<"Minor: "<<minor<<'\n';
	std::cout<<"Expected graduation year: "<<graduationYear<<'\n';
}

