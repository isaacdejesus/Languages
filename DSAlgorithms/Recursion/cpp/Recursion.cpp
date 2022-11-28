#include <iostream>

int numberInLine(int);
int sumOfNumbers(int);
std::string stringReversal(std::string);
bool palindrome(std::string);
int binarySearch(int arr[], int left, int right, int x);
long int fib(long int n);
int main()
{
    std::cout<<numberInLine(5)<<'\n';
    std::cout<<sumOfNumbers(5)<<'\n';
    std::cout<<stringReversal("hello")<<'\n';
    std::cout<<palindrome("sarah")<<'\n';
    std::cout<<palindrome("hannah")<<'\n';
    int sortedNums[] = {1, 0, 3, 4, 6, 7, 8, 9, 11, 16, 17};
    std::cout<<binarySearch(sortedNums, 0, 10, 9)<<'\n';
    std::cout<<fib(5)<<'\n';
    return 0;
}
//simulates being last person waiting in line
int numberInLine(int num)
{
    if(num <= 1)
        return 1;
    return numberInLine(num - 1) + 1;
}
//returns sum of numbers up to n
int sumOfNumbers(int n)
{
    if(n <= 1)
        return 1;
    return sumOfNumbers(n - 1) + n;
}
//reverses a string
std::string stringReversal(std::string input)
{
    if(input.size() == 0)
        return "";
    return stringReversal(input.substr(1, std::string::npos)) + input[0];
}
bool palindrome(std::string input)
{
    if(input.size() == 0 || input.size() == 1)
        return true;
    if(input[0] == input[input.size() - 1])
        return palindrome(input.substr(1, input.size() - 2));
    return false;
}
int binarySearch(int arr[], int left, int right, int x)
{
    if(left > right)
        return -1;
    int mid = (left + right) / 2;
    if(arr[mid] == x)
        return mid;
    if(arr[mid] > x)
        return binarySearch(arr, left, mid - 1, x);
    return binarySearch(arr, mid + 1, right, x);
}
long int fib(long int n)
{
    if(n <= 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
