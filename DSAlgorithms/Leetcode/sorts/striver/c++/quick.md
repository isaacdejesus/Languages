### Quicksort
- Quicksort works by selecting a pivot element and placing pivot in correct sorted location.
    - Select Pivot - Think of it as subarrays
        - Shift elements < pivot to left of pivot - Think as subarray of elements < pivot to the left of pivot
        - Shift elements > pibot to right of pivot - Think as subarray of elements > pivot to the right of pivot
- When algo is done placing all elements in correct sorted location, entire array will be sorted
- Pivot can be any element. Ideally, it is the mid element for better complexity but we will use first element 
```
[4, 6, 2, 5, 7, 9, 1, 3]

First run: Pivot is 4
left subarr [2, 1, 3]
right subarr [6, 5, 7, 9]
.:. Hv: [2, 1, 3] & [4] & [6, 5, 7, 9]
         < pivot    pivot   > pivot
NOTE: Pivot: 4 is in correct loc relative to remaining elements even though entire arr isn't sorted.
      All elements to the left of pivot are smaller than pivot
      All elements to the right of pivot are greater than pivot
Since pivot is in correct location, we can then run the same algo on left and right subararys

Second run: [2, 1, 3], pivot is 2
left subarr [1]
right subarr [3]
.:. hv: [1]  &   [2]  &   [3]
        < p       p        > p
NOTE: Hv reached base cases: arrays of single element.
On way back of recursion, sort by combining left + pivot + right
In this case: [1] + [2] + [3]
Returning a sorted arr [1, 2, 3]

Third run: [6, 5, 7, 9], pivot is 6
left subarr [5]
right subarr [7, 9]
.:. hv: [5]  &  [6]  & [7, 9]

Fourth run: [7, 9], pivot [7]
left subarr []
right subarr [9]
.:. hv: [] [7] [9]
.s. base case  we can combine left + pivot + right 
returning sorted [7, 9]

Back to parent we hv: [5] [6] [7, 9]
                       l   p   r
We can combine: left, pivot and right
[5, 6, 7, 9]

Finally back to main call we have: pivot [4]
left [1, 2, 3]
right [5, 6, 7, 9]

Combine sorted arr: left + pivot + right
[1, 2, 3, 4, 5, 6, 7, 9]
```

### pseudocode
- Sort in place by using pointers to determine where left and right subarrays start and end like on merge sort
[4, 6, 2, 5, 7, 9, 1, 3]
 0  1  2  3  4  5  6  7             <-- indexes
low                  high          <-- low and high mark start and end of arr
pivot = arr[low]                   <-- recall pivot can be anything. we use first element of arr/subarr
- Rearranging arr to place pivot in correct location:
    - Shift elements > p to right of pivot.
    - Shift elements < p to left of pivot. 
    - Recursion will be called on resulting left and right subarr later
    - Use two pointer i and j: i at start of arr and j at end of subarr
        - Advance i if arr[i] < pivot .:. stop when arr[i] > pivot
        - Decrease j if arr[j] > p    .:. stop when arr[j] < pivot
        - When both i and j become false means those 2 elements are on wrong sides .:. swap

```
 i                    j
[4, 6, 2, 5, 7, 9, 1, 3]
 0  1  2  3  4  5  6  7             <-- indexes
low                  high          <-- low and high mark start and end of arr
pivot = arr[low]                   <-- recall pivot can be anything. we use first element of arr/subarr

Start by advancing i until arr[i] > pivot which indicates arr[i] is on wrong side
i = 0, pivot: 4, arr[i] = 4, 4 == 4 .:. i++
i = 1, pivot: 4, arr[i] = 6, 4 < 6  .:. stop bc 6 is out of place

Since i reached element out of order, switch over to j
Advance j until arr[j] < pivot which indicates arr[j] is on wrong side
j = 7, pivot: 4, arr[j] = 3, 4 > 3 .:. stop bc 3 is out of place

Since both arr[i] and arr[j] are out of place we can swap them to their correct side

    i                 j
[4, 3, 2, 5, 7, 9, 1, 6]
 0  1  2  3  4  5  6  7             <-- indexes

Go back to i advancing until arr[i] > pivot
i = 1, pivot: 4, arr[i] = 3, 4 > 3 .:. i++
i = 2, pivot: 4, arr[i] = 2, 4 > 2 .:. i++
i = 3, pivot: 4, arr[i] = 5, 4 < 5 .:. stop since 5 is out of place

j = 7, pivot: 4, arr[j] = 6, 4 < 6 .:. j--
j = 6, pivot: 4, arr[j] = 1, 4 > 1 .:. stop since 1 is out of place

Both i and j are out of place .:. swap

          i        j
[4, 3, 2, 1, 7, 9, 5, 6]
 0  1  2  3  4  5  6  7             <-- indexes

i = 3, pivot: 4, arr[i] = 1, 4 > 1 .:. i++
i = 4, pivot: 4, arr[i] = 7, 4 < 7 .:. stop since 7 is out of place

j = 6, pivot: 4, arr[j] = 5, 4 < 5 .:. j--
j = 5, pivot: 4, arr[j] = 9, 4 < 9 .:. j--
j = 4, pivot: 4, arr[j] = 7, 4 < 7 .:. j--
j = 3, pivot: 4, arr[j] = 1, 4 > 1 .:. stop at position j crossed i

 p        j  i     
[4, 3, 2, 1, 7, 9, 5, 6]
 0  1  2  3  4  5  6  7             <-- indexes
finally place pivot at correct location by swapping pivot/arr[low] with arr[j]

[1, 3, 2, 4, 7, 9, 5, 6]
 0  1  2  3  4  5  6  7             <-- indexes
          p
Everything left of p is < p and everything right of p is > p 

Pivot's sorted location becomes the *partition index* 
low                   high
[1, 3, 2, 4, 7, 9, 5, 6]
 0  1  2  3  4  5  6  7             <-- indexes
          ^
          |
          pivot/partition index
Bc now quicksort can be called on left and right subarrays as:
quicksort(arr, low, partition_index - 1)  -> [1, 3, 2]
quicksort(arr, partition_index + 1, high) -> [7, 9, 5, 6]
```
```
Pseudocode
quicksort(arr, low, high)
{
    if(low < high)
    {
        partition_index = f(arr, low, high);
        quicksort(arr, low, partition_index - 1);
        quicksort(arr, partition_index + 1, high);
    }
}
int f(arr, low, high)
{
    pivot = arr[low];
    i = low;
    j = high;
    while(i < j)  //while j hasn't crossed i. j > i means done partitioning arr
    {
        //arr[i] <= pivot and arr[j] >= pivot make sure repeated values == pivot are next pivot
        while(arr[i] <= pivot && i <= high - 1) //-1 to avoid out of boundarie errors
            i++;
        while(arr[j] >= pivot && > <= low + 1)  //+1 to avoid out of boundarie errors
            j--;
        if(i < j)
            swap(arr[i], arr[j])
    }
    swap[arr[low], arr[j]];  //place pivot at correct sorted location
    return j;  //return partition index or pivot's correct sorted location index
}
```
- Finally remember each time the recursion run, the pivot is place at the correct sorted location. 
- Looks like tail recursion to me. All work is done at call time.
- Take pivot, place it in sorted order, do the same for left and right subarrays. By the time reach base case,
  all elements would have been placed in correct order within original arr since work is done in place.
