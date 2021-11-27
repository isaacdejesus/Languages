#include <iostream>
#include <vector>
#include <string>

int main()
{
//constructors
//default constructor
std::vector<int> default_constructor = {5, 2, 9, 3, 7};

//fill constructor-creates vector with n elements with n copies of same val
std::vector<std::string> fill_constructor(6, "Potato");
//print using auto loops
for(auto element: fill_constructor)
    std::cout<<element<<' ';

for(std::string element : fill_constructor)
    std::cout<<element<<' ';
std::cout<<'\n';
//range constructor
//iterates through vector and copies all values from start to end range
std::vector<int> range_constructor(default_constructor.begin(), default_constructor.end());
//print  
for(int element : range_constructor)
    std::cout<<element<<' ';
std::cout<<'\n';
//range constructor can also be used to copy values from an array
int arr [] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::vector<int> vector_from_array(arr, arr + sizeof(arr) / sizeof(int));
//can also do
int size_of_array = sizeof(arr) / sizeof(arr[0]);
std::vector<int> vector_from_array1(arr, arr + size_of_array);
//can also just copy certain range of array
std::vector<int> vector_from_array2(arr, arr + 5);
for(auto element : vector_from_array2)
    std::cout<<element<<' ';
std::cout<<'\n';

//copy constructor- can copy another vector
std::vector<int> copy_of_vector(default_constructor);

for(auto element : copy_of_vector)
    std::cout<<element<<' ';
std::cout<<'\n';

//Vector methods
std::cout<<"----------- ------------ ----------- ---------- -- -"<<'\n';

//get number of elements in vector
std::cout<<default_constructor.size()<<'\n';

//check if vector is empty
if(default_constructor.empty())
    std::cout<<"Vector is empty"<<'\n';
else
    std::cout<<"Vector contains elements"<<'\n';
//access elements
std::cout<<default_constructor.front();
std::cout<<default_constructor[1];
std::cout<<default_constructor.at(2);
std::cout<<default_constructor.back()<<'\n';

//modifiers
//push_back() add element to the end
std::vector<int> vec;
vec.push_back(66);
vec.push_back(83);
//insert element at specified location. Iterator points to vec[1]
std::vector<int>::iterator it;
it = vec.begin() + 1;
vec.insert(it, 9);

for(auto element : vec)
    std::cout<<element<<' ';
std::cout<<"Values after using assign: "<<'\n';
//assign - deletes contents of vector and assigns new values
it = default_constructor.begin(); //set iterator to first val of vector
vec.assign(it, it + 2); //assign first 2 values of default to vec

for(auto element : vec)
    std::cout<<element<<' ';
std::cout<<'\n';

//delete last element
vec.pop_back();

//clear deletes all elements from vector and sets size to 0
vec.clear();

vec.push_back(2);
vec.push_back(4);
vec.push_back(33);
vec.push_back(9);
vec.push_back(0);

for(auto element : vec)
    std::cout<<element<<' ';
std::cout<<'\n';
//delete elements
vec.erase(vec.begin() + 1); //delete the 2nd element
for(auto element : vec)
    std::cout<<element<<' ';
std::cout<<'\n';

//delete range of elements
vec.erase(vec.begin(), vec.begin() + 2); //delete first 2 elements
for(auto element : vec)
    std::cout<<element<<' ';
std::cout<<'\n';


return 0;
}
