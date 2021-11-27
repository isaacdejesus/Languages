#include <iostream>
#include <string>
typedef std::string anagrams;
void insertion( char arr[], int n);
void check (anagrams one, anagrams two);

int main()
{
    anagrams one, two;
    std::cout<<"Enter a two words"<<'\n';
    std::cin>>one>>two;
    std::cout<<'\n';
    check(one, two);
    return 0;
}

void insertion( char arr[], int n)
{
    int i, key, j;
    for(i=1; i<n; i++)
    {
        key=arr[i];
        j=i-1;
    while(j>=0 && arr[j]>key)
    {
        arr[j +1 ] = arr[j];
        j=j-1;
    }
    arr[j+1]=key;
    }
}

void check (anagrams one, anagrams two)
{
    char arr1[10];
    char arr2[10];
    int counter=0;
    if(one.size()!=two.size())
        std::cout<<"String of different sizes can't be anagrams"<<'\n';
    else
    {
        // str2arr(one);
        // str2arr(two);
        for(int i=0; i<one.size(); i++)
        {
            arr1[i]=one[i]; 
            std::cout<<arr1[i];       
        }
        for(int i=0; i<two.size(); i++)
        {
            arr2[i]=two[i]; 
            std::cout<<arr2[i];       
        }
        std::cout<<'\n';
        insertion(arr1, one.size());
        insertion(arr2, two.size());
        for(int i=0; i<one.size(); i++)
            {
                if(arr1[i]==arr2[i])
                    counter++;
            }
        if(counter==one.size())
            std::cout<<"yes";
        else
            std::cout<<"no";
    }
    
}

