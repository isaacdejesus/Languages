#include <iostream>
#include "deepcopy.h"
#include <string>

int main()
{
	deepcopy<std::string> *fruitsArray= new deepcopy<std::string>(6);
	fruitsArray->populateArray();
	fruitsArray->display();

	//making a copy of the fruits object
	deepcopy<std::string> *fruitsCopy=new deepcopy<std::string>(*fruitsArray);
	fruitsCopy->display();

}