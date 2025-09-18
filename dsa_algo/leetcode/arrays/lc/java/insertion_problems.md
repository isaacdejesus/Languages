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