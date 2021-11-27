#include <iostream>
#include <string>

template <class DataType>
class opoverloading
{
	private:
		DataType income;
	public:
		opoverloading(DataType income);
		//operator overloading function
		opoverloading operator+(opoverloading other);
		void display();
};

template <class DataType>
opoverloading<DataType>::opoverloading(DataType income)
{
	this->income=income;
}

template <class DataType>
opoverloading<DataType> opoverloading<DataType>::operator+(opoverloading other)
{
	opoverloading tempObject(0);
	tempObject.income=income + other.income;

	return tempObject;
}

template <class DataType>
void opoverloading<DataType>::display()
{
	std::cout<<income<<'\n';
}

