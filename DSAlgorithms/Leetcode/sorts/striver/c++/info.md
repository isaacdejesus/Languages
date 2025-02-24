### Selection sort
- Each iteration select smallest element and place at insert index. Where insert index
  starts at 0 and increases each loop
```
13, 46, 24, 52, 20, 9
i = 0;
smallest is 9, .:. swap 9 to i = 0 and place 13 wherever 9 was
*9*, 46, 24, 52, 20, *13*

i = 1
smallest is 13 .:. swap 13 to i = 1 and place 46 wherever 13 was
9, *13*, 24, 52, 20, *46*

i = 2
9, 13, *20*, 52, *24*, 46

i = 3
9, 13, 20, *24*, *52*, 46

i = 4
9, 13, 20, 24, *46*, *52*
```
- Note there is no need to run loop for last element (n - 1) .:. loop runs until <= n - 2
```
n = 6
9, 13, 20, 24, 46, 54
0  1   2   3   4   5
               n-2 n-1
               |
               this is the last value to check.
               there is no need to check n-1 since all previous vals are already in place
               .:. nothing to swap it w/ meaning n-1 already in place after n-2 check
```
```c++
#include<bits/stdc++.h>
void selection(std::vector<int>& arr)
{
    for(int i = 0; i <= arr.size() - 2; i++)
    {
        int min = i;
        for(int j = i; j < arr.size(); j++)
        {
            if(arr[j] < arr[min]) 
                min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
```
### Bubble sort
- Compare adjacent values and swap if [i + 1] is > [i]
```
13, 46, 24, 52, 20, 9

1st run checks until n-1
13, 24, 46, 52, 20, 9

13, 24, 46, 20, 52, 9

13, 24, 46, 20, 9, 52
Note by end of first run largest val is at end of arr

2nd run checks until n-2
13, 24, 20, 46, 9|    52

13, 24, 20, 9, 46|    52
note by end of second run last 2 values are largest and in place

3rd run runs until n-3
13, 20, 24, 9|       46, 52

13, 20, 9, 24
last 3 values are largest in place

4th run
13, 9, 20|           24, 46, 52

9, 13, 20
last 4 vals are in place

5th run
9, 13 |              20, 24, 46, 52
last 5 vals already in place
6th run: only one element left, .:. done 
9 |                  13, 20, 24, 46, 52

9, 13, 20, 24, 46, 52
```
```c++
#include<bits/stdc++.h>
void bubble(std::vector<int>& arr)
{
    for(int i = arr.size() - 1; i >= 1; i-- )
    {
        for(int j = 0; j < i ; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```
- Outer loop determines up to what point check/swap pairs. Starts at n(entire arr), 
  then n-1, then n-2,  down to 1
```
Ex. 13, 46, 24, 52, 20, 9
size = 6 
i = 5;
j 0 -> < 5: 0 1 2 3 4
Above will check entire arr and swap up to 4th index: 13, 46, 24, 52, 20*, 9

i = 4;
j 0 -> < 4: 0 1 2 3
Check up to 3rd index: 13, 24, 46, 20*, 9| 52

i = 3;
j 0 -> < 3: 0 1 2 
check up to 2nd index: 
13, 24, 20*, 9| 46, 52

i = 2;
j 0 -> < 2: 0 1
check up to 1st index:
13, 20*, 9| 24 46, 52

and so on bc note last j index can swap with final unsorted element if needed
For instance 20 can swap with 9 since 9 is smaller
```
### insertion sort
- For each element check if it values to left are smaller, if so swap until can no longer swap.
  Then given element will be at correct loc. Do same with next element for all elements in arr
- Start at index 1 since values index 0 has nothing to left .:. nothing to compare to  
```
14 9 15 12 6 8 13

i = 1
j = i/1
arr[j] < arr[j - 1] .:. swap
9 14 15 12 6 8 13

i = 2
j = i/2
arr[j] < arr[j - 1] .:. Do nothing
arr[2] < arr[1]
15 < 14
j = i - 1/ 1
arr[j] < arr[j - 1] .:. Do nothing
arr[1] < arr[0]
15 < 9 

i = 3
j = i/3
ugh and so on
```
```c++
void insertion(std::vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
```
