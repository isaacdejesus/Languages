#include <iostream>
#include "rectangle.h"

int main()

{
    //Creating two rectangle objects
    Rectangle one(5.0,3.0);
    Rectangle two(11.0,7.0);
    //creating a third rectangle and setting it to size of rectangle one and two
    Rectangle three=two+one;
    std::cout<<"Length of Rectangle three is: "<<three.getLength()<<'\n';
    std::cout<<"Width of Rectangle three is: "<<three.getWidth()<<'\n';

    //checking the = operator
    Rectangle four=three;
    //checking the == operator
    std::cout<<(one==two)<<": False, because rectangle one is not equal to rectangle two"<<'\n'; //expect return to be false/0
    std::cout<<(three==four)<<": True, because rectangle three has same dimensions as rectangle four"<<'\n';  //expect return to be true/1
    //checking the != operator
    std::cout<<(one!=two)<<": True, because rectangle one is not equal to rectangle two"<<'\n'; //expect return to be true/1
    std::cout<<(three!=four)<<": False, because rectangle four and rectangle three have same dimensions"<<'\n';  //expect return to be false/0
    //checking is operator > works
    std::cout<<(two>one)<<": True, because area of rectangle two is greater than area of rectangle one"<<'\n'; //expect true/1
    std::cout<<(one>two)<<": False, because area of rectangle one is less than area of rectangle two"<<'\n'; //expect false/0
    //checking >>operator
    //create a rectangle. Then use >> to ask user for length and width
    Rectangle five;
    std::cin>>five;
    //checking <<operator. To print out rectangle dimensions and area
    std::cout<<five;

    return 0;
}