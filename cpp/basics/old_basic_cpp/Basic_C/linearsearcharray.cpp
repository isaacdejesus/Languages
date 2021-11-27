#include <iostream>
#include <string.h>
//defines names to be var of type string
typedef std::string names;
//defines sizes to be a var of type int
typedef int sizes;
//takes in an array and populates it with user define input of type string/names
void createArray(names arr[], sizes n);
int linearSearch(names arr[], sizes n, names toFind);
int main()
{
    sizes sizeofArray;
    names *array;
    names toLook;
    std::cout<<"Enter a size for the array"<<'\n';
    std::cin>>sizeofArray;
    std::cout<<'\n';
    array= new names[sizeofArray];
    std::cout<<"Enter "<<sizeofArray<<" strings to store in the array: "<<'\n';
    createArray(array, sizeofArray);
    std::cout<<"Enter a string to find within the array: "<<'\n';
    std::cin>>toLook;
    std::cout<<linearSearch(array, sizeofArray, toLook);
    return 0;
}

void createArray(names arr[], sizes n)
{
    names temp;
    for(int i=0; i<n; i++)
    {
        std::cin>>temp;
        arr[i]=temp;
    }
}  

int linearSearch( names arr[], sizes n, names toFind)
{
    int returnVal=-1;
    for(int i=0; i<n; i++)
        {
            //std::cout<<"Comparing: "<<toFind<< " with "<<arr[i]; 
            if((arr[i].compare(toFind))==0)
            {
                std::cout<<arr[i];
                returnVal= i;
            }
            // else
            //     return -1;
        }
        return returnVal;
}