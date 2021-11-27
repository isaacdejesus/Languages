#include <iostream>
#include <string>
//template only works for string? Only able to ini array with constructor to either strings or ints
template <class DataType>
class deepcopy
{
	private:
		int size;
		DataType *array;

	public:
		//There are three different constructors
		//The dafault constructor doesn't take any parameters.
		//Default constructor can be bipassed as follows
		//deepcopy();
		deepcopy(int size=0);
		//The above constructor acts as both default by setting size to zero if no parameter is given
		//Also acts as overloaded when a parameter is given

		//Next we demonstrate the deep copy constructor. Useful when dynamic arrays or pointers are present.
		//It makes a copy of an object and stores it at a different address to avoid changes in one affecting the other
		deepcopy(deepcopy &copy);
		void populateArray();
		
		//display function
		void display();
};

template <class DataType>
deepcopy<DataType>::deepcopy(int size)
{	
	//another way to set size
	this->size=size;
	
	//create dynamis array of size
	array= new DataType[size];

	//ini array
	for(int i=0; i<size; i++)
	{
		array[i]="";
	}
}

template <class DataType>
deepcopy<DataType>::deepcopy(deepcopy &copy)
{
	//copy size of object to new object
	size=copy.size;
	//copy the array
	array= new DataType[size];
	//copy the values of the object into the new array
	for( int i=0; i<size; i++)
	{
		array[i]=copy.array[i];
	}
}

template <class DataType>
void deepcopy<DataType>::display()
{
	for(int i=0; i<size;i++)
	{	
		std::cout<<array[i]<<" ";
	}
	std::cout<<'\n';
}

template<class DataType>
void deepcopy<DataType>::populateArray()
{
	std::cout<<"Enter "<<size<<" values to store in the array: "<<'\n';
	for(int i=0; i<size; i++)
	{
		std::cin>>array[i];
	}
}
