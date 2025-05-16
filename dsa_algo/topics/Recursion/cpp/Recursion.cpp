#include <iostream>
#include <vector>

int numberInLine(int);
int sumOfNumbers(int);
std::string stringReversal(std::string);
bool palindrome(std::string);
int binarySearch(int arr[], int left, int right, int x);
long int fib(long int n);
void merge_sort(std::vector<int> &vec, int start, int end);
void merge(std::vector<int> &vec, int start, int mid, int end);
void q_sort(int arr[], int low, int high);
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
    std::cout<<'\n';
    std::vector<int> a_vector = {8, 3, 2, 4, 0};
    merge_sort(a_vector, 0, 4);
    for(auto element: a_vector)
        std::cout<<element;
    std::cout<<'\n';
    int arr[] = {2, 1, 5, 3, 9};
    q_sort(arr, 0, 4);
    for(auto element: arr)
        std::cout<<element;
    std::cout<<'\n';
    
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
void merge_sort(std::vector<int> &vec, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(vec, start, mid);
        merge_sort(vec, mid + 1, end);
        merge(vec, start, mid, end);
    }
}
void merge(std::vector<int> &vec, int start, int mid, int end)
{
    std::vector<int> temp;
    temp.reserve(end - start + 1);
    int i = start, j = mid + 1, k = 0;
    //linear comparison
    while(i <= mid && j <= end)
    {
        if(vec[i] <= vec[j])
            temp[k++] = vec[i++];
        else
            temp[k++] = vec[j++];
    }
    //append remaining elements from left subarr to sorted arr
    while(i <= mid)
    {   
        temp[k] =  vec[i];
        k++;
        i++;
    }
    //append remaining elements from right subarr to sorted arr
    while(j <= end)
    {
        temp[k] = vec[j];
        k++;
        j++;
    }
    //set sorted subarr back into original arr
    //only modify subarr portion in original arr
    for(i = start; i <= end; i++)
        vec[i] = temp[i -start];
}

void q_sort(int arr[], int low, int high)
{
    if(low >= high)
        return;
    int s = low;
    int e = high;
    int m = s + (e - s) /2;
    int pivot = arr[m];
    while(s <= e)
    {
        while(arr[s] < pivot)
            s++;
        
        while(arr[e] > pivot)
            e--;
        
        if(s  <= e)
        {
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }
    q_sort(arr, low, e);
    q_sort(arr, s, high);
}
 
