## #27 Remove element
- Given [int] and int val, remove all occurrences of val in [int] in place
- Order of elements can be changed.
- Return number of elements in [int] which are not equal to val
- Change [int] such that first k elements are elements not equal to val. The remaining elements 
of [int] are not important as well as the size of [int]
- Return k, the number of elements not equal to val

```
input: [3, 2, 2, 3], val = 3
output: 2, [2, 2, _, _]
Function returns k = 2 which are elements left after removing val = 3
```
```
input: [0, 1, 2, 2, 3, 0, 4, 2], val = 2
output: 5, [0, 1, 4, 0, 3, _, _, _]
Function returns k = 5 which are elements left after removing val = 2
Note: remaining elements can be in any order as long as they are in the first
k indexes of arr. It doesn't matter what values are past k index
```
```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int insert_loc = 0;
        for( int i = 0; i < nums.length; i++)        
        {
            if(nums[i] != val)
            {
                nums[insert_loc] = nums[i];
                insert_loc++;
            }
        }
        return insert_loc;
    }
}
```
- Use k as insert index
- Iterate and insert [i] != val into k

## # 26 Remove duplicates from sorted array
- Given sorted [int], remove duplicates in place such that ea unique element appears only once
- Order of elements should remain the same
- Return number of unique elements in [int]
- Place the unique elements in first k elements of [int] in order they were initially present
- Remaining elements are not important
- Return k

```
input: [1, 1, 2]
output: 2, [1, 2]
k = 2, since there are only 2 unique elements
```
```
input: [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
output: 5, [0, 1, 2, 3, 4, _, _, _, _, _]
k = 5, since there are 5 unique numbers
```
```java
class Solution {
    public int removeDuplicates(int[] nums) {
       int insert_loc = 1;
       for(int i = 1; i < nums.length; i++) 
       {
            if(nums[i] != nums[i - 1])
            {
                nums[insert_loc] = nums[i];
                insert_loc++;
            }
       }
       return insert_loc;
    }
}
```
- insert_loc = 1 and iterate starting from index 1
- Iterate forward comparing [i] != [i -1]
- Inserting [insert_loc] = [i], if [i] != [i - 1]