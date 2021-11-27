#include <iostream>
#include <string>
//templates allow you to use the function with any data type
template <class AnyData>
AnyData add( AnyData a, AnyData b);
int main()
{
    //Now, we can call the add funcition with various data types without having to create multiple functions for each
    std::string a="potato";
    std::string b=" i am";
    char c='h';
    char d='p';
    std::cout<<add(1,1);
    std::cout<<add(c, d);
    std::cout<<add(1.0, 9.2);
    std::cout<<add(b,a);
    return 0;
}
template <class AnyData>
AnyData add(AnyData a, AnyData b)
{
    std::cout<<'\n';
    AnyData c;
    c=a + b;
    return c;
}