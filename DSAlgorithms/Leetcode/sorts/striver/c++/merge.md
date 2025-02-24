# Merge Sort is made up of 2 steps: Divide & Merge
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

###  merge_sort Pseudocode
- Instead of creating multiple subarrays, use pointers to keep track of where ea sub
  arr starts and ends. Here use low and high to mark start and end of subarr
- Note low/high used to keep track of subarrays to me able to perform merge in place
  in same arr
[3, 2, 4, 1, 3]
 low         high
- array can be divided in two halves: mid = (low + high)/2
- Call mergesort on each subarray to continue dividing it to base case or size 1
    - mergesort(arr, low, mid);  //sorts first half of arr
    - mergesort(arr, mid + 1, high);  //sorts second half of arr
- After dividing, merge the resulting arrays
    - merge(arr, low, mid, high
```c++
merge_sort(arr, low, high)
{
    if(low >= high)
        return;
    int mid = (low + high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
```
```
Initial call: [3, 2, 4, 1, 3], low = 0, high = 4
merge_sort(arr, 0, 4);                          [3, 2, 4, 1, 3]
    mid = (0 + 4)/2 = 2;                        /             \
    merge_sort(arr, 0, 2);              [3, 2, 4]              \
    merge_sort(arr, 3, 4);                                      [1, 3]
    merge(low, mid, high);

Note recursion will continue on left branch/first rec call until reaching base case
Whenever that call returns, the next line will execute

[3, 2, 4], low = 0, high = 2
merge_sort(arr, 0, 2);                           [3, 2, 4]
    mid = (0 + 2)/2 = 1;                        /        \
    merge_sort(arr, 0, 1);                    [3, 2]      \
    merge_sort(arr, 2, 2);                                  [4]
    merge(low, mid, high);

[3, 2], low = 0, high = 1
merge_sort(arr, 0, 1);                           [3, 2]
    mid = (0 + 1)/2 = 0;                        /      \
    merge_sort(arr, 0, 0);                    [3]       \
    merge_sort(arr, 1, 1);                              [2]
    merge(low, mid, high);

[3], low = 0, high = 0
merge_sort(arr, 0, 0);                           [3]
    if(low >= high)
        return;
    //base case reached since single element. Return sorted arr [3]

[2], low = 1, high = 1
merge_sort(arr, 1, 1);                           [2]
    if(low >= high)
        return;
    //base case reached since single element. Return sorted arr [2]

NOTE: At this point both left and right subarrays are returned sorted .:. merge can run 
      and merge them!

[3, 2], low = 0, high = 1
merge_sort(arr, 0, 1);                           [3, 2]
    mid = (0 + 1)/2 = 0;                        /      \
    merge_sort(arr, 0, 0);                    [3]       \   <--- returns [3]
    merge_sort(arr, 1, 1);                              [2] <--- returns [2]
    merge(low, mid, high);   <---- Here, ready to merge: [3] & [2] returning sorted [2, 3]
RECALL that since in place the original [3, 2] subarray becomes [2, 3]


[3, 2, 4], low = 0, high = 2
merge_sort(arr, 0, 2);                           [3, 2, 4]
    mid = (0 + 2)/2 = 1;                        /        \
    merge_sort(arr, 0, 1);                    [2, 3]      \        <--- just returned sorted [2, 3]
    merge_sort(arr, 2, 2);                                  [4]    <--- this line can run now
    merge(low, mid, high);

[4], low = 2, high = 2
merge_sort(arr, 2, 2);                           [4]
    if(low >= high)
        return;
    //base case reached since single element. Return sorted arr [4]

[3, 2, 4], low = 0, high = 2
merge_sort(arr, 0, 2);                           [3, 2, 4]
    mid = (0 + 2)/2 = 1;                        /        \
    merge_sort(arr, 0, 1);                    [2, 3]      \        <--- returned sorted [2, 3]
    merge_sort(arr, 2, 2);                                  [4]    <--- just returned sorted [4]
    merge(low, mid, high);   <---- Here, merge: [2,3] & [4] returning [2, 3, 4]
RECALL that since in place the original [3, 2, 4] subarray becomes [2, 3, 4]

Initial call: [3, 2, 4, 1, 3], low = 0, high = 4
merge_sort(arr, 0, 4);                          [3, 2, 4, 1, 3]
    mid = (0 + 4)/2 = 2;                        /             \
    merge_sort(arr, 0, 2);              [3, 2, 4]              \           <--- Just returned sorted [2, 3, 4]
    merge_sort(arr, 3, 4);                                      [1, 3]     <--- this line can run now
    merge(low, mid, high);


[1, 3], low = 3, high = 4
merge_sort(arr, 3, 4);                           [1, 3]
    mid = (3 + 4)/2 = 3;                        /     \
    merge_sort(arr, 3, 3);                    [1]      \        
    merge_sort(arr, 4, 4);                              [3]    
    merge(low, mid, high);

[1], low = 3, high = 3
merge_sort(arr, 3, 3);                          [1]
    if(low >= high)
        return;
    //base case reached since one element. Return sorted arr[1]

[3], low = 4, high = 4
merge_sort(arr, 4, 4);                          [3]
    if(low >= high)
        return;
    //base case reached since one element. Return sorted arr[3]

[1, 3], low = 3, high = 4
merge_sort(arr, 3, 4);                           [1, 3]
    mid = (3 + 4)/2 = 3;                        /     \
    merge_sort(arr, 3, 3);                    [1]      \        returned sorted [1]
    merge_sort(arr, 4, 4);                              [3]     returned sorted [3]
    merge(low, mid, high);  <-- can now merge [1] & [3] returning sorted [1, 3]

Initial call: [3, 2, 4, 1, 3], low = 0, high = 4
merge_sort(arr, 0, 4);                          [3, 2, 4, 1, 3]
    mid = (0 + 4)/2 = 2;                        /             \
    merge_sort(arr, 0, 2);              [3, 2, 4]              \           <--- Just returned sorted [2, 3, 4]
    merge_sort(arr, 3, 4);                                      [1, 3]     <--- Just returned sorted [1, 3]
    merge(low, mid, high);  <-- can now merge [2, 3, 4] & [1, 3] returning sorted [1, 2, 3, 3, 4]
Original array at end of algo will be [1, 2, 3, 3, 4]
```

### merge pseudocode
```
merge(arr, low, mid, high)
{
    temp[];
    left = low;
    right = mid + 1;
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
            temp.add(arr[left]);
            left++;
        else
        {
            temp.add(arr[right]);
            right++;
        }
        while(left <= mid)
        {
            temp.add(arr[left]);
            left++;
        }
        while(right <= high)
        {
            temp.add(arr[right]);
            right++;
        }
        for(i = low -> high)
            arr[i] = temp[i - low];
    }
}
```
```
Initial arr: [3, 1, 2, 4, 1, 5, 6, 2, 4]
Indexes:      0, 1, 2, 3, 4, 5, 6, 7, 8
After calls are merged the final merge will be:
[1, 1, 2, 3, 4]  &  [2, 4, 5, 6]
 0, 1, 2, 3, 4       5, 6, 7, 8   <--- indexes in original arr
 ^           ^       ^        ^
 |           |       |        |
 low         mid      mid + 1   high
 left                 right

Iteration 1: Compare arr[left] & arr[right], take smallest;
[1, 1, 2, 3, 4]  &  [2, 4, 5, 6]
 0, 1, 2, 3, 4       5, 6, 7, 8   <--- indexes in original arr
 ^           ^       ^        ^
 |           |       |        |
 left        mid     right    high

left is smallest, add to sorted arr and left++

sorted [1]
Iteration 2: Compare arr[left] & arr[right], take smallest;
[1, 1, 2, 3, 4]  &  [2, 4, 5, 6]
 0, 1, 2, 3, 4       5, 6, 7, 8   <--- indexes in original arr
    ^        ^       ^        ^
    |        |       |        |
    left     mid     right    high
left is smallest, add to sorted arr and left++
sorted[1, 1]

Iteration 3: Compare arr[left] & arr[right], take smallest;
[1, 1, 2, 3, 4]  &  [2, 4, 5, 6]
 0, 1, 2, 3, 4       5, 6, 7, 8   <--- indexes in original arr
       ^     ^       ^        ^
       |     |       |        |
       left  mid     right    high
left is smallest, add to sorted arr and left++
sorted[1, 1, 2]

Iteration 4: Compare arr[left] & arr[right], take smallest;
[1, 1, 2, 3, 4]  &  [2, 4, 5, 6]
 0, 1, 2, 3, 4       5, 6, 7, 8   <--- indexes in original arr
          ^  ^       ^        ^
          |  |       |        |
       left  mid     right    high
right is smallest, add to sorted arr and right++
sorted[1, 1, 2, 2]

Iteration 5: Compare arr[left] & arr[right], take smallest;
[1, 1, 2, 3, 4]  &  [2, 4, 5, 6]
 0, 1, 2, 3, 4       5, 6, 7, 8   <--- indexes in original arr
          ^  ^          ^     ^
          |  |          |     |
       left  mid        right high
left is smallest, add to sorted arr and left++
sorted[1, 1, 2, 2, 3]

Iteration 6: Compare arr[left] & arr[right], take smallest;
[1, 1, 2, 3, 4]  &  [2, 4, 5, 6]
 0, 1, 2, 3, 4       5, 6, 7, 8   <--- indexes in original arr
             ^          ^     ^
             |          |     |
             mid        right high
             left
left is smallest, add to sorted arr and left++
sorted[1, 1, 2, 2, 3, 4]

Iteration 7: Compare arr[left] & arr[right], take smallest;
[1, 1, 2, 3, 4]  &  [2, 4, 5, 6]
 0, 1, 2, 3, 4       5, 6, 7, 8   <--- indexes in original arr
             ^ ^        ^     ^
             | |        |     |
             m l        right high
left is out of bounds/elements, .:. add all elements from other arr to back of sorted               
sorted[1, 1, 2, 2, 3, 4, 4, 5, 6]
```
- Once have merged subarrs and merged them in sorted order. Need to put them back into
  original arr or subarray section they belong to
```
for(i = low -> high)
    arr[i] = temp[i - low];
```
```c++
#include <bits/stdc++.h>
void merge(std::vector<int> &arr, int low, int mid, int high)
{
    std::vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while( left <= mid )
    {
        temp.push_back(arr[left]);
        left++;
    }
    while( right <= high )
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}
void merge_sort(std::vector<int> &arr, int low, int high)
{
    if(low >= high)
        return;
    int mid = (low + high) /2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
```
- Using head recursion:
    - Divide arr in half until base case. 
    - Upon reaching base cases, call the merge function which merges base cases/subarrays in sorted order.
      this would be work done at return time on way back from recursion
