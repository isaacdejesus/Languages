#include <iostream>

bool canSum(int, int[], int);
int main()
{
    int arr1[] = {2, 4};
    int arr2[] = {2, 3, 5, 7};
    std::cout<<canSum(7, arr1, 2);
    std::cout<<canSum(7, arr2, 4);
    return 0;
}

bool canSum(int targetSum, int numbers[], int arrSize)
{
    if(targetSum == 0)
        return true;
    if(targetSum < 0)
        return false;
    for(int i = 0; i < arrSize; i++ )
    {
        int remainder = targetSum - numbers[i];
        if(canSum(remainder, numbers, arrSize) == true)
            return true;
    }
    return false;
}
