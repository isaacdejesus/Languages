## In place operations introduction
- In place operations reduce space complexity
- Given [int] return [int] where even indexed elements are squared
```
in:  [9, -2, -9, 11, 56, -12, -3]
      0   1   2  3   4    5    6
      sq      sq     sq        sq
out: [81, -2, 81, 11, 3136, -12, 9]
```
```java
public int[] sq_even(int[] arr, int length){
    if(arr == null)
        return arr;
    for(int i = 0; i < length; i += 2)
        arr[i] *= arr[i];
    return arr;
}
```
- Just iterate [int] starting from index 0. Iterate at 2 steps to skip odd indexes
- By modifying [int] in place, space is saved

### Replace elements with greatest element on right side
- Given [int] replace every element in arr with greatest element among elements to its right and replace
  last element with -1
- Return resulting arr
```
in : [17, 18, 5, 4, 6, 1]
out : [18, 6, 6, 6, 1, -1]

in : [400]
out : [-1]
```
```java
class Solution {
    public int[] replaceElements(int[] arr) {
        int current_max = arr[arr.length - 1];  //save last element as current_max
        int current_val = 0;  //keep track of current_val prior to overwriting it
        arr[arr.length - 1] = -1;  //overwrite last element with -1
        for(int i = arr.length - 2; i >= 0; i--) //iterate in reverse, skipping last index since set to -1
        {
            current_val = arr[i];  //save current val
            arr[i] = current_max;  //overwrite current val with max value to the right
            if(current_val > current_max) //update max value to the right if needed
                current_max = current_val;
        }
        return arr;
    }
}
```
- Set last element to -1
- Iterate from the back of arr, keeping track of highest value iterated through from right
### #283 Move zeroes
- Given [int], move all 0's to end while keeping order of non-zero elements
- Do it in place without making a cp of [int]
```
in : [0, 1, 0, 3, 12]
out : [1, 3, 12, 0, 0]

in : [0]
out : [0]
```
```java
class Solution {
    public void moveZeroes(int[] nums) {
        int insert_loc = 0;   //insert non-zeros at start of arr
        int val_at_insert;    //value currently at insert loc. Save it to swap later
        for(int i = 0; i < nums.length; i++)
        {
            if(nums[i] != 0)
            {
                val_at_insert = nums[insert_loc];  //save the 0 to swap it with [i]
                nums[insert_loc] = nums[i];       //insert [i] to [insert_loc]
                insert_loc++;
                nums[i] = val_at_insert;          //place 0 at [i]
            }
        }
    }
}
```
- Iterate, inserting non-zeros at the beginning of arr and swapping 0 to where non-zero used to be. 
  will cause zeros to bubble to the end. 
- Trace on paper is faster

### #905 Sort array by parity 
- Given [int], move even ints to beginning of arr, followed by odd ints
- Solution is same as above problem
```java
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int even_insert = 0;
        int val_at_insert;
        for(int i = 0; i < nums.length; i++)
        {
            if(nums[i] % 2 == 0) //check if even
            {
                val_at_insert = nums[even_insert]; //save val at insert index
                nums[even_insert] = nums[i];
                even_insert++;
                nums[i] = val_at_insert;
            }
        }
        return nums;
    }
}
```