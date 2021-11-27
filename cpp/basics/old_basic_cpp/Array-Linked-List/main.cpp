#include <iostream>
#include "arrayLinkedList.h"
using namespace std;

int main( )
{
	arrayLinkedList<int>  potato;
	arrayLinkedList<int>  chicken;
	chicken=potato;
	//potato.print();
	//std::cout<<potato.search(8);
	//potato.remove(-1);
	potato.insert(3);
	potato.insert(5);
	potato.insert(9);
	potato.insert(11);
	potato.insert(15);
	potato.insert(7);
	potato.insert(4);
	potato.insert(1);
	potato.insert(99);
	potato.remove(-1);
	potato.print();

	return 0;
}