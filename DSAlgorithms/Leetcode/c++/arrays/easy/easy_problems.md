## Largest element in an array
Q: Given arr of ints, return largest int.
[3, 2, 1, 5, 2] -> 5

### Brute force: Sort arr and return last element
[3, 2, 1, 5, 2] --sort--> [1, 2, 2, 3, 5]
                                       ^
                                       |
                                       largest
- Time complexity O(nlogn) due to sort using merge or quicksort
- Space complexity O(1)

### Optimal solution: 
- created *largest* variable to keep track of largest element
- iterate arr and compare current element to *largest*. Take largest and update *largest* if needed
```
[3, 2, 1, 5, 2], largest = arr[0] = 3
i = 0, largest: 3, largest = max(largest, 3) -> 3
i = 1, largest: 3, largest = max(largest, 2) -> 3
i = 2, largest: 3, largest = max(largest, 1) -> 3
i = 3, largest: 3, largest = max(largest, 5) -> 5
i = 4, largest: 5, largest = max(largest, 2) -> 5
Done looping return -> largest: 5
```
- Time complexity O(n)

```c++
#include<bits/stdc++.h>
int largest(std::vector<int> &arr, int n)
{
    int largest = arr[0];
    for(int i = 0; i < n; i ++)
    {
        if(arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}
```
## Second largest in an array
Q: Given arr of ints, returns second largest int
[1, 2, 4, 7, 7, 5] -> 5

### Brute force:
- Sort array
- Since last element is largest, iterate backwards comparing largest to i
    - *second_largest* = -1;  //ini to -1 bc there might not be a second largest if all values are same
        - ex. [7, 7, 7, 7, 7, 7] there is no *second_largest*
    - If largest == arr[i], i--
    - if largest != arr[i] then this is second largest
    ```c++
        //after sorting iterate from back looking for 2nd_largest
        for(i = n - 2; i >= 0; i--)
        {
            if(arr[i] != largest)
            {
                second_largest = arr[i];
                break;  //since found second_largest
            }
        }
    ```
- Complexity: O(nlogn) due to merge/quicksort
### Better-ish:
- Loop once to find greatest element 
```
largest = arr[0];
for(i = 0; i < n; i++)
    if(arr[i] > largest)
        largest = arr[i];

[1, 2, 4, 7, 7, 5]
largest = arr[0]
i = 0, largest = 1, arr[i] = 1. largest = max(largest, 1) -> 1
i = 1, largest = 1, arr[i] = 2. largest = max(largest, 2) -> 2
i = 2, largest = 2, arr[i] = 4. largest = max(largest, 4) -> 2
i = 3, largest = 4, arr[i] = 7. largest = max(largest, 7) -> 7
i = 4, largest = 7, arr[i] = 7. largest = max(largest, 7) -> 7
i = 5, largest = 7, arr[i] = 5. largest = max(largest, 5) -> 7
```
- From first pass obtain largest = 7
- loop again, looking for second largest, updating as long as arr[i] != largest
```
second_largest = -1;
for(i = 0; i < n; i++)
{
    if(arr[i] > second_largest && arr[i] != largest)
        second_largest = arr[i];
}
[1, 2, 4, 7, 7, 5], largest = 7
second_largest =arr[0]
i = 0, second_largest = 1, arr[i] = 1. second_largest = max(second_largest, 1) -> 1
i = 1, second_largest = 1, arr[i] = 2. second_largest = max(second_largest, 2) -> 2
i = 2, second_largest = 2, arr[i] = 4. second_largest = max(second_largest, 4) -> 4
i = 3, second_largest = 4, arr[i] = 7. not calculated bc arr[i]/7 == largest/7
i = 4, second_largest = 4, arr[i] = 7. not calculated bc arr[i]/7 == largest/7
i = 5, second_largest = 4, arr[i] = 5. second_largest = max(second_largest, 5) -> 5
```
- By end of 2nd loop the *second_largest* is 5
- Complexity O(2n) 
### Optimal: Use two pointers to keep track of largest and *second_largest*
- Solution assumes no neg numbers
- largest = arr[0], *second_largest* = -1;
- loop:
    - If current is > largest, then largest becomes 2nd largest and current becomes largest
    - Also check if current > *second_largest*, if yes, update *second_largest*
```
[1, 2, 4, 7, 7, 5], largest = arr[0], second_largest = -1

i = 0, largest = 1, second_largest = -1, arr[i] = 1. 1 == 1 ...(do nothing)
                                                     ^    ^
                                                     |    |
                                                   arr[i] largest
i = 1, largest = 1, second_largest = -1, arr[i] = 2. 2 > 1. Update largest and second_largest
       second_largest = 1;                           
       largest = 2

i = 2, largest = 2, second_largest = 1, arr[i] = 4. 4 > 2. Update largest and second_largest
       second_largest = 2;
       largest = 4

i = 3, largest = 4, second_largest = 2, arr[i] = 7. 7 > 4. Update largest and second_largest
       second_largest = 4;
       largest = 7
i = 4, largest = 7, second_largest = 4, arr[i] = 7. 7 == 7. ...(do nothing)
i = 5, largest = 7, second_largest = 4, arr[i] = 5. 5 > 7. Check is 5 > second_largest? 
                                                                    5 > 4, yes, .:. update second_largest
second_largest = 5;
```
- Loop done, return *second_largest* = 5
- NOTE: solution computes both second largest and second smallest

## Check if arr is sorted
[1, 2, 2, 3, 3, 4] -> yes
[1, 2, 1, 3, 4] -> no
- Iterate 
    - check if arr[i] > arr[i - 1], continue
    - if arr[i] < arr[i - 1], return false
    - if reach end of loop return true
    ```
    psudocode
    for(i = 1; i < n; i++)
    {
        if(arr[i] > arr[i - 1])
            continue
        else
            return false;
    }
    return true
    ```
- Time O(n)

## Remove duplicates in place from sorted arr
[1, 1, 2, 2, 2, 3, 3] -> 3
- If there are 3 unique elements, place those 3 unique elements in the first 3 slots of arr
- Doesn't matter what elements take up the remaining slots
- .:. need to modify original arr and return how many unique elements are in arr

### Brute force: use a set
- Iterate adding vals to set
- After iteration set will only have unique vals
- Then take elements from set and insert them into arr starting at index 0
```
set<int> a_set;
for(i = 0; i < n; i++)
    a_set.insert(arr[i])

[1, 1, 2, 2, 2, 3, 3]
 0  1  2  3  4  5  6  <--indexes

After iteration: a_set[1, 2, 3]

-> insert values from set into arr
index = 0;
for(auto it: a_set)
{
    arr[insex] = it;
    index++;
}
i = 0, take 1 from set and insert at index 0
[1, 1, 2, 2, 2, 3, 3]
 0  1  2  3  4  5  6  <--indexes
 i
i++

i = 1, take 2 from set and insert at index 1
[1, 2, 2, 2, 2, 3, 3]
 0  1  2  3  4  5  6  <--indexes
    i 
i++

i = 2, take 3 from set and insert at index 2
[1, 2, 3, 2, 2, 3, 3]
 0  1  2  3  4  5  6  <--indexes
       i 
i++

Set out of values .:. done. Return i -> 3
```
- Time complexity: O(nlogn) to insert into set + O(n) to insert unique vals from set into arr
- Space complexity: O(n)
### Optimal: Use fact that arr is sorted
- First element will remain in place 
- Loop, comparing current to first element
    - If currnt == first, continue
    - if current != first, insert current at next slot
    - Repeat
    ```
    insert_index = 0
    for(i = 1; i < n; i++)
{
    if(arr[i] != arr[insert_index])
    {
        arr[insert_index + 1] = arr[i];
        insert_index++;
    }
    return insert_index + 1;
}
    [1, 1, 2, 2, 2, 3, 3], insert_index = 1
        ^
        |
        insert_index
     i = 1, previous: 1. 1 == 1, continue
     i = 2, previous: 1. 2 != 1, it's a new unique val, insert at insert_index
    [1, 2, 2, 2, 2, 3, 3], insert_index = 1
           ^
           |
           insert_index
     i = 3, previous: 2. 2 == 2, continue
     i = 4, previous: 2. 2 == 2, continue
     i = 5, previous: 2. 3 != 2, it's a new unique val, insert at insert_index
    [1, 2, 3, 2, 2, 3, 3], insert_index = 1
              ^
              |
              insert_index
     i = 6, previous: 3. 3 == 3, continue
     done looping. return insert_index = 4
    ```
- Ugh, pseudo and tracing don't match but you get the idea
## Left rotate array by one place
- Given an arr, left rotate by one place
[1, 2, 3, 4, 5] -> [2, 3, 4, 5, 1]
- Note left shifting by one causes all elements to shift to the left by one. First element becomes last
- Loop from 1 to n - 1 setting arr[i - 1] = arr[i]
- Finally set arr[n - 1] = arr[0]
```
temp = arr[0];
for(i = 1; i < n; i++)
    arr[i - 1] = arr[i];
arr[n - 1] = temp;
```
- Time complexity O(n)
- Space complexity O(1)

## Left rotate arr by d places
[1, 2, 3, 4, 5, 6, 7], d = 2  -> [3, 4, 5, 6, 7, 1, 2]
[1, 2, 3, 4, 5, 6, 7], d = 3  -> [4, 5, 6, 7, 1, 2, 3]
- Note if d = arr.size(), first d elements are appended to end of array, while remaining elements are shifted d times
  to the left
[1, 2, 3, 4, 5, 6, 7], d = 7  -> [1, 2, 3, 4, 5, 6, 7]
- Note that if d/shift == arr.size() then result is input arr

