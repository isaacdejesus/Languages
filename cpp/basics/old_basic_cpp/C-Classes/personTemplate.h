#include <iostream>
#include <string>

template <class DataType1, class DataType2>
class personTemplate
{
	protected:
		DataType1 firstName;
		DataType1 lastName;
		DataType2 age;

	public:
		personTemplate();
		personTemplate(DataType1 firstNameIn, DataType1 lastNameIn, DataType2 ageIn);
		void setFirstName(DataType1 firstNameIn);
		void setLastName(DataType1 lastNameIn);
		void setAge(DataType2 ageIn);
		void displayPersonInfo();
};

template <class DataType1, class DataType2>
personTemplate<DataType1, DataType2>::personTemplate()
{
	firstName="";
	lastName="";
	age=0;
}

template <class DataType1, class DataType2>
personTemplate<DataType1, DataType2>::personTemplate(DataType1 firstNameIn, DataType1 lastNameIn, DataType2 ageIn)
{
	firstName=firstNameIn;
	lastName=lastNameIn;
	age=ageIn;
}

template <class DataType1, class DataType2>
void personTemplate<DataType1, DataType2>::setFirstName(DataType1 firstNameIn)
{
	firstName=firstNameIn;
}

template <class DataType1, class DataType2>
void personTemplate<DataType1, DataType2>::setLastName(DataType1 lastNameIn)
{
	lastName=lastNameIn;
}

template <class DataType1, class DataType2>
void personTemplate<DataType1, DataType2>::setAge(DataType2 ageIn)
{
	age=ageIn;
}

template <class DataType1, class DataType2>
void personTemplate<DataType1, DataType2>::displayPersonInfo()
{
	std::cout<<"Name: "<<firstName<<" "<<lastName<<'\n';
	std::cout<<"Age: "<<age<<'\n';
}



