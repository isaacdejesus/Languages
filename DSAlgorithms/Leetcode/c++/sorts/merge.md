#Merge Sort is made up of 2 steps: Divide & Merge
[3, 1, 2, 4, 1, 5, 2, 6, 4]
### Divide: Divides arr in equal halves down to base case, arr of size 1
```
                 [3, 1, 2, 4, 1, 5, 2, 6, 4]
                /                           \ 
             [3, 1, 2, 4, 1]                   [5, 2, 6, 4]
             /              \                  /           \
          [3, 1, 2]         [4, 1]           [5, 2]         [6, 4]
          /        \        /     \         /      \        /     \
        [3, 1]     [2]     [4]    [1]      [5]     [2]     [6]    [4]
        /    \
      [3]    [1]
```
- Note base case is single element since it can no longer be divided
### Merge: Takes 2 subarrays and merges them into a single ordered arr
```
                 [3, 1, 2, 4, 1, 5, 2, 6, 4]
                /                           \ 
             [3, 1, 2, 4, 1]                   [5, 2, 6, 4]
             /              \                  /           \
          [3, 1, 2]         [4, 1]           [5, 2]         [6, 4]
          /        \        /     \         /      \        /     \
        [3, 1]     [2]     [4]    [1]      [5]     [2]     [6]    [4]
        /    \
      [3]    [1]
      ----------------------MERGE------------------------------------
       \   /        |       |      |        |        |       |      |
      [1, 3]       [2]     [4]    [1]      [5]      [2]     [6]    [4]
           \       /        \     /           \     /         \    /
           [1, 2, 3]         [1, 4]            [2, 5]         [4, 6] 
                  \          /                       \        /
                [1, 1, 2, 3, 4]                     [2, 4, 5, 6]
                              \                      /
                             [1, 1, 2, 2, 3, 4, 4, 5, 6]
```
- Merge takes smallest element from subarrays at ea step
- Note, this is head recursion. These sorted arrays bubble up the recursion tree. Meaning
  the sorted subarrays are returned and to parent array from which they originally came.
```
Merge algo uses 2 pointers. They start at index 0 of subarrays to be merged. At ea step
elements are compared, smallest is added to sorted arr, its pointer is advanced and repeat.
Once a subarray runs out of elements, the remaining elements of other arr are added to end
of sorted arr.

[ sorted result arr]
[1, 1, 2, 3, 4] [2, 4, 5, 6]
 i               j
result [1]

[1, 1, 2, 3, 4] [2, 4, 5, 6]
    i            j
result [1, 1]

[1, 1, 2, 3, 4] [2, 4, 5, 6]
       i         j
result [1, 1, 2]

[1, 1, 2, 3, 4] [2, 4, 5, 6]
          i      j
result [1, 1, 2, 2]

[1, 1, 2, 3, 4] [2, 4, 5, 6]
          i         j 
result[1, 1, 2, 2, 3]

[1, 1, 2, 3, 4] [2, 4, 5, 6]
             i      j
result [1, 1, 2, 2, 3]

[1, 1, 2, 3, 4] [2, 4, 5, 6]
             i      j
result [1, 1, 2, 2, 3, 4]

[1, 1, 2, 3, 4] [2, 4, 5, 6]
               i    j
-> i is out of bounds, .:. add remaining elements of other arr to end of sorted arr
result [1, 1, 2, 2, 3, 4, 4, 5, 6]
```

### Pseudocode
- Instead of creating multiple subarrays, use pointers to keep track of where ea sub
  arr starts and ends. Here use low and high to mark start and end of subarr
[3, 2, 4, 1, 3]
 low         high
- array can be divided in two halves: mid = (low + high)/2
- Call mergesort on each subarray to continue dividing it to base case or size 1
    - mergesort(arr, low, mid);  //sorts first half of arr
    - mergesort(arr, mid + 1, high);  //sorts second half of arr
- After dividing, merge the resulting arrays
    - merge(arr, low, mid, high
