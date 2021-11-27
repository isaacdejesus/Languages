#include <iostream>
typedef float numbers;
typedef int sizes;

void createArray(numbers arr[], sizes size);
void bubbleSort(numbers arr[], sizes size);
void displayArray(numbers arr[], sizes size);
int binarySearch(numbers arr[], sizes size, numbers toFind);

int main()
{
	sizes size;
	numbers* array;
	numbers toFind;
	std::cout << "Enter a size for the array: " << '\n';
	std::cin >> size;
	std::cout<< '\n';
	array = new numbers[size];
	createArray(array, size);
	bubbleSort(array, size);
	displayArray(array, size);
	std::cout << '\n';
	std::cout << "Enter a value to search: " << '\n';
	std::cin >> toFind;

	std::cout<<binarySearch(array, size, toFind);


}

void createArray(numbers arr[], sizes size)
{
	numbers temp;
	std::cout << "Enter " << size << " numbers to add to array: " << '\n';
	for (int i = 0; i < size; i++)
	{
		std::cin >> temp;
		arr[i] = temp;
	}
}

void bubbleSort(numbers arr[], sizes size)
{
	numbers temp;
	for (int i=0; i<size; i++)
		for (int j = 0; j < size-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
}

void displayArray(numbers arr[], sizes size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i];
		
}

int binarySearch(numbers arr[], sizes size, numbers toFind)
{
	//int low, mid, high = 0;
	int returnVal = -1;
	int low=0;
	int high=size-1;
    int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
        std::cout<<" mid is: "<<mid;
		if (toFind == arr[mid])
			{returnVal = mid;
			return returnVal;
			}
		else if (toFind < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return returnVal;
}