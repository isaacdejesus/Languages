## #724 Find pivot index
- Given [int] calc pivot index of [int]
- Pivot index is index where sum of all values left of index equal to sum of all values right of index
- If index is on left edge of [int], then left sum is 0 bc there are no elements to the left
- Above applies to right edge of [int] as well
- Return leftmost pivot index.
- If no pivot return -1

```
in : [1, 7, 3, 6, 5, 6]
out : 3
```
```
in : [1, 2, 3]
out : -1 
```
```
in : [2, 1, -1]
out : 0
```
```java
class Solution {
    public int pivotIndex(int[] nums) {
        int total_sum = 0;
        int left_sum = 0;
        int right_sum = 0;
        for(int i = 0; i < nums.length; i++)
            total_sum += nums[i];
        for(int i = 0; i < nums.length; i++)
        {
            right_sum = total_sum - left_sum - nums[i];
            if(right_sum == left_sum)
                return i;
            left_sum += nums[i];
        }
        return -1;
    }
}
```
- Sum all values in [int]
- iterate
    - calc right_sum = total_sum - left_sum - [i]
    - if right_sum == left_sum -> return i
    - else left_sum +=[i]
- If reach end of [int] return -1 bc no pivot exists
## Large number at least twice of others
- Given [int], determine if largest element is at least 2x as much as eevery other element in [int]
- If yes, return index of largest element
- Else return -1

```python
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        max_val = 0
        max_index = 0
        for i in range(len(nums)):
            if(nums[i] > max_val):
                max_val = nums[i]
                max_index = i
        for i in range(len(nums)):
            if nums[i] != max_val:
                if max_val < nums[i] * 2:
                    return -1
        return max_index
```
- Iterate to find largest value and save index
- Iterate to compare [i] * 2 < max_value
    - if no, return -1
    - If reach end of loop return max_index bc it means max_val is 2x greater than every element
      in [int]

## #66 Plus one
- Given [int] which represents a large integer, where each [i] represents ith int of integer
- Digits are ordered from most significant to least significant. Left to right order.
- Increment large integer by one and return resulting [int]
```
in [1, 2, 3]
out: [1, 2, 4]
```
```
in [4, 3, 2, 1]
out: [4, 3, 2, 2]
```
```
in : [9]
out: [1, 0]
```
```java
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for(int i = n - 1; i >= 0; i--)  //iterate from back of arr
        {
            if(digits[i] == 9)  //if [i] == 9, set it to 0
                digits[i] = 0;
            else{               //if [i] is not 9, add + 1 and return
                digits[i]++;
                return digits;
            }
        }
        //if reached end of loop means only had 9s to set to 0, .:. need to prefix [int] with 1
        digits = new int[n + 1];
        digits[0] = 1;
        return digits;
    }
}
```
- Iterate in reverse
- If [i] < 9, add 1 to it and return
- if [i] is 9, set to 0 and insert 1 at beginning of arr