## # 1089 Duplicate zeros
- Given [int] duplicate ea occurrence of 0. Shifting remaining elements to the right
- Note: Items beyond length of original arr are discarded. 
```
Input       [1, 0, 2, 3, 0, 4, 5, 0]
Output      [1, 0, 0, 2, 3, 0, 0, 4]
```
- Note # of elements lost/trimmed at the end of the array = # of 0's duplicated
```
Input       [1, 0, 2, 3, 0, 4, 5, 0]
                ^        ^   are duplicated
                               ^  ^  are trimmed off      
            [1, 0, 0, 2, 3, 0, 0, 4] [5, 0]
                ^           ^   are duplicated
                                      ^  ^ are trimmed off
Output      [1, 0, 0, 2, 3, 0, 0, 4]
                ^           ^    duplicated
```
- Note since 2 zeroes are duplicated, the last 2 elements are trimmed off at the end of []
### Approach
1. Find number of zeroes to be duplicated: int possible_duplicates = 0;
    - Determine how many elements from [input] will be part of [output].
    - possible_duplicates should not include any zeroes which will be trimmed off
    - possible_duplicates is number of elements to be trimmed off [input]
2. Be sure not to duplicate last zero in [output]
```
[8, 4, 5, 0, 0, 0, 0, 7]
          ^  ^  duplicate
                ^ last element in [output]. Do not duplicate
                   ^  ^  trimmed off
[8, 4, 5, 0, 0, 0, 0]
```
3. Iterate from end of arr and copy elements to the end of arr
``` java
public class duplicateZeros {
    public static void duplicate_zeros(int[] arr){
        int possible_duplicates = 0;
        int length_ = arr.length - 1;
        for(int l = 0; l <= length_ - possible_duplicates; l++)
        {
            if(arr[l] == 0)
            {
                if(l == length_ - possible_duplicates)
                {
                    arr[length_] = 0;
                    length_ -= 1;
                    break;
                }
                possible_duplicates++;
            }
        }
        int last = length_ - possible_duplicates;
        for(int i = last; i >= 0; i--)
        {
            if(arr[i] == 0)
            {
                arr[i + possible_duplicates] = 0;
                possible_duplicates--;
                arr[i + possible_duplicates] = 0;
            }
            else
            {
                arr[i + possible_duplicates] = arr[i];
            }
        }
    }
}
```
### Walkthrough
```
[1, 0, 2, 3, 0, 4, 5, 0]
int possible_duplicates = 0;
int length_ = arr.length - 1;    => 8 - 1 => 7
```
- Get length of [out] 
``` java
for(int l = 0; l <= length_ - possible_duplicates; l++)
    {
        if(arr[l] == 0)
        {
            if(l == length_ - possible_duplicates)
            {
                arr[length_] = 0;
                length_ -= 1;
                break;
            }
            possible_duplicates++;
        }
    }
```
```
l : 0 
l <= length_ - possible_duplicates
0 <= 7       - 0
0 <= 7   : Yes, enter if 
if(arr[l] == 0)
   arr[0] == 0
       1  == 0: No, go to next iteration
-----
l : 1 
l <= length_ - possible_duplicates 
1 <= 7       - 0 
1 <= 7   : Yes, check if 
Current l: [1, 0, 2, 3, 0, 4, 5, 0]
               ^

if (arr[l] == 0)  
    arr[1] == 0: Yes, enter if
         0 == 0: Yes, enter if

if(l == length_ - possible_duplicates)
   1 == 7       - 0: No, do nothing

possible_duplicates++ => 1
-----
l : 2 
l <= length_ - possible_duplicates 
2 <= 7       - 1
2 <= 6: Yes, check if
Current l: [1, 0, 2, 3, 0, 4, 5, 0]
                  ^

if (arr[l] == 0)  
    arr[2] == 0: 
         2 == 0: No, go to next iteration
-----
l : 3
l <= length_ - possible_duplicates
3 <= 7       - 1
3 <= 6: Yes, check if
Current l: [1, 0, 2, 3, 0, 4, 5, 0]
                     ^

if (arr[l] == 0)  
    arr[3] == 0: 
         3 == 0: No, go to next iteration
-----
l : 4
1 <= length_ - possible_duplicates
4 <= 7       - 1
4 <= 6: Yes, check if
Current l: [1, 0, 2, 3, 0, 4, 5, 0]
                        ^

if (arr[l] == 0)  
    arr[4] == 0: Yes, enter if
         0 == 0: Yes, enter if

if(l == length_ - possible_duplicates)
   4 == 7       - 1: No, do nothing
   4 == 6: No, do nothing

possible_duplicates++ => 2
-----
l : 5
l <= length_ - possible_duplicates
5 <= 7       - 2
5 <= 5: Yes, check if
Current l: [1, 0, 2, 3, 0, 4, 5, 0]
                           ^
if(arr[l] == 0)
   arr[5] == 0: No
        4 == 0: No, go to next iteration

-----
l : 6
l <= length_ - possible_duplicates
6 <= 7       - 2
6 <= 5: No, break loop, done.
```
```java
[1, 0, 2, 3, 0, 4, 5, 0]
    ^        ^
length_ = 7;
possible_duplicates = 2;
int last = length_ - possible_duplicates;
for(int i = last; i >= 0; i--)
    {
        if(arr[i] == 0)
        {
            arr[i + possible_duplicates] = 0;
            possible_duplicates--;
            arr[i + possible_duplicates] = 0;
        }
        else
        {
            arr[i + possible_duplicates] = arr[i];
        }
    }
```
```
[1, 0, 2, 3, 0, 4, 5, 0]
    ^        ^
length_ = 7;
possible_duplicates = 2;
int last = length_ - possible_duplicates;
           7 - 2 = 5
last = 5;

i : 5
i >= 0
5 >= 0: Yes, check if.

if(arr[i] == 0)
        4 == 0: No, enter else
arr[i + possible duplicates] = arr[i];
arr[5 + 2] = arr[5];
arr[7] = 4
Before: [1, 0, 2, 3, 0, 4, 5, 0]
                        i     i + possible_duplicates     
After:  [1, 0, 2, 3, 0, 4, 5, 4]
-----
i : 4
i >= 0
4 >= 0: yes, check if

if(arr[i] == 0)
        0 == 0: Yes, enter if
arr[i + possible_duplicates] = arr[i];
arr[4 + 2] = arr[4];
arr[6] = 0;
Before: [1, 0, 2, 3, 0, 4, 5, 4]
                     i     i + possible_duplicates     
After:  [1, 0, 2, 3, 0, 4, 0, 4]
possible_duplicates--
possible_duplicates = 1
arr[i + possible_duplicates] = arr[i];
arr[4 + 1] = arr[4];
arr[5] = 0;
Before: [1, 0, 2, 3, 0, 4, 0, 4]
                     i  i + possible_duplicates     
After:  [1, 0, 2, 3, 0, 0, 0, 4]
-----
i : 3
i >= 0
3 >= 0: Yes, check if.

if(arr[i] == 0)
        3 == 0: No, enter else
arr[i + possible duplicates] = arr[i];
arr[3 + 1] = arr[3];
arr[4] = 3
Before: [1, 0, 2, 3, 0, 0, 0, 4]
                  i  i + possible_duplicates     
After:  [1, 0, 2, 3, 3, 0, 0, 4]
-----
i : 2
i >= 0
2 >= 0: Yes, check if.

if(arr[i] == 0)
        2 == 0: No, enter else
arr[i + possible duplicates] = arr[i];
arr[2 + 1] = arr[2];
arr[3] = 2
Before: [1, 0, 2, 3, 3, 0, 0, 4]
               i  i + possible_duplicates     
After:  [1, 0, 2, 2, 3, 0, 0, 4]
-----
i : 1
i >= 0
1 >= 0: Yes, check if.

if(arr[i] == 0)
        0 == 0: Yes, enter if
arr[i + possible_duplicates] = arr[i];
arr[1 + 1] = arr[1];
arr[2] = 0;
Before: [1, 0, 2, 3, 3, 0, 0, 4]
            i  i + possible_duplicates     
After:  [1, 0, 0, 2, 3, 0, 0, 4]
possible_duplicates--
possible_duplicates = 0
arr[i + possible_duplicates] = arr[i];
arr[1 + 0] = arr[1];
arr[1] = 0;
Before: [1, 0, 0, 2, 3, 0, 0, 4]
            i/i + possible_duplicates     
After:  [1, 0, 0, 2, 3, 0, 0, 4]
-----
i : 0
i >= 0
0 >= 0: Yes, check if.
if(arr[i] == 0)
        1 == 0: No, enter else
arr[i + possible duplicates] = arr[i];
arr[0 + 0] = arr[0];
arr[0] = 1;
Before: [1, 0, 0, 2, 3, 0, 0, 4]
         i/i + possible_duplicates     
After:  [1, 0, 0, 2, 3, 0, 0, 4]
```
Ugh, this is a really complex one tbh

## #88 merge sorted array
- Given sorted[int1] & sorted[int2] and two ints m & n representing the # of elements
in each array. 
- Merge sorted[int1] & sorted[int2] in sorted order. 
- Final sorted[out] should not be returned. Should be stored in sorted[int1]
- sorted[int1] has length m + n, where first m elements are elements of [int1] to be merged
and last n elements are set to 0. [int2] has length n

- Ex1
```
input 1 = [1, 2, 3, 0, 0, 0], m = 3
input 2 = [2, 5, 6], n = 3
output = [1, 2, 2, 3, 5, 6]
```
- Ex2
```
input 1 = [1], m = 1
input 2 = [], n = 0
output = [1]
```
- Ex3
```
input 1 = [0], m = 0
input 2 = [1], n = 1
output = [1]
```
### Approach
- Use two pointers, one for each arr.
- Compare values at pointers, inserting largest to the back of [int1] and decreasing pointer

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
       int p1 = m - 1;
       int p2 = n - 1;
       for(int insert_loc = m + n - 1; insert_loc >= 0; insert_loc--) 
       {
            if(p2 < 0) // all vals have been inserted. done
                break;
            if(p1 >= 0 && nums1[p1] > nums2[p2])
                nums1[insert_loc] = nums1[p1--];
            else
                nums1[insert_loc] = nums2[p2--];
       }
    }
}
```
### Walkthrough
```
input 1 = [1, 2, 3, 0, 0, 0], m = 3
input 2 = [2, 5, 6], n = 3

int p1 = m - 1; => 2
int p2 = n - 1; => 2

for(int insert_loc = m + n - 1; insert_loc >= 0; insert_loc--) 
--->
insert_loc = 3 + 3 - 1 = 5;
```
```
insert_loc : 5
p1 : 2
p2 : 2
input 1 = [1, 2, 3, 0, 0, 0]
                 ^        ^
                 p1       insert_loc
input 2 = [2, 5, 6]
                 ^
                 p2
if(p1 >= 0 && nums1[p1] > nums2[p2])
    2 >= 0 &&        3 > 6  : No, go to else
else
    nums1[insert_loc] = nums2[p2--];
    nums1[5] = nums2[p2--];
    nums1[5] = nums2[6];

out = [1, 2, 3, 0, 0, 6]
insert_loc-- -> 4;
p2-- -> 1
```
```
insert_loc : 4
p1 : 2
p2 : 1
input 1 = [1, 2, 3, 0, 0, 6]
                 ^     ^
                 p1    insert_loc
input 2 = [2, 5, 6]
              ^
              p2

if(p1 >= 0 && nums1[p1] > nums2[p2])
    2 >= 0 &&        3 > 5  : No, go to else
else
    nums1[insert_loc] = nums2[p2--];
    nums1[4] = nums2[p2--];
    nums1[4] = nums2[1];
out = [1, 2, 3, 0, 5, 6]
insert_loc-- -> 3;
p2-- -> 0
```
```
insert_loc : 3
p1 : 2
p2 : 0
input 1 = [1, 2, 3, 0, 5, 6]
                 ^  ^
                 p1 insert_loc
input 2 = [2, 5, 6]
           ^
           p2

if(p1 >= 0 && nums1[p1] > nums2[p2])
    2 >= 0 &&        3 > 2  : Yes, insert
    nums1[insert_loc] = nums1[p1--];
    nums1[3] = nums1[2];
out = [1, 2, 3, 3, 5, 6]
insert_loc-- -> 2
p1-- -> 1
```
```
insert_loc : 2
p1 : 1
p2 : 0
input 1 = [1, 2, 3, 3, 5, 6]
              ^  ^
              p1 insert_loc
input 2 = [2, 5, 6]
           ^
           p2
if(p1 >= 0 && nums1[p1] > nums2[p2])
    1 >= 0 &&        2 > 2  : No, go to else

else
    nums1[insert_loc] = nums2[p2--];
    nums1[2] = nums2[p2--];
    nums1[2] = nums2[0];
out = [1, 2, 2, 3, 5, 6]
insert_loc-- -> 1
p2-- -> -1
```
```
insert_loc : 1
p1 : 1
p2 : -1

if(p2 < 0) // all vals have been inserted. done
    break;

DONE
output [ 1, 2, 2, 3, 5, 6]
```