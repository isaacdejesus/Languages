## #1051 Height checker
- Students are asked to line up based on height. Represented by sorted[expected], where [i] is
  height of ith student.
- Given [heights] which represent current order students are lined up.
- Return number of indices where heights[i] != expected[i]

### Approach
- Create a cp of heights, sort it and compare values. Mismatches++
```java
class Solution {
    public int heightChecker(int[] heights) {
        int[] expected = Arrays.copyOf(heights, heights.length);
        Arrays.sort(expected);
        int mismatches = 0;
        for(int i = 0; i < heights.length; i++)
        {
            if(heights[i] != expected[i])
                mismatches++;
        }
        return mismatches;
    }

```
## # 487 Max consecutive ones II
- Given binary [int], return max consecutive 1's in [int] if allowed to flip at most one 0
```
in : [1, 0, 1, 1, 0]
out : 4
```
```
in : [1, 0, 1, 1, 0, 1]
out : 4 
```
```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int longest = 0;
        int left = 0;
        int right = 0;
        int zeroes = 0; 
        while(right < nums.length)       
        {
            if(nums[right] == 0)
                zeroes++;
            while(zeroes == 2)
            {
                if(nums[left] == 0)
                    zeroes--;
                left++;
            }
            longest = Math.max(longest, right - left + 1);
            right++;
        }
        return longest;
    }
}
```
```
longest = 0;
left = 0;
right = 0;
zeroes = 0;
[1, 0, 1, 1, 0]
 ^
 l/r

while(right < nums.length)       
[r] != 0 -> do nothing
zeroes != 2 -> do nothing
longest = Math.max(longest, right - left + 1);
      0 = Math.max(      0,     0 -    0 + 1)
      0 = Math.max(0, 1);
      longest = 1

right++ -> 1
```
```
longest = 1;
left = 0;
right = 1;
zeroes = 0;
[1, 0, 1, 1, 0]
 ^  ^
 l  r

while(right < nums.length)       
[r] == 0 .:. zeroes++ -> 1
zeroes != 2 -> do nothing
longest = Math.max(longest, right - left + 1);
      1 = Math.max(      1,     1 -    0 + 1);
      1 = Math.max(0, 2);
      longest = 2;
right++ -> 2
```
```
longest = 2;
left = 0;
right = 2;
zeroes = 1;
[1, 0, 1, 1, 0]
 ^     ^
 l     r

while(right < nums.length)       
[r] == 0 .:. zeroes++ -> 1
zeroes != 2 -> do nothing
longest = Math.max(longest, right - left + 1);
      2 = Math.max(      2,     2 -    0 + 1);
      2 = Math.max(2, 3);
      longest = 3;
right++ -> 3
```
```
longest = 3;
left = 0;
right = 3;
zeroes = 1;
[1, 0, 1, 1, 0]
 ^        ^
 l        r

while(right < nums.length)       
[r] == 0 .:. zeroes++ -> 1
zeroes != 2 -> do nothing
longest = Math.max(longest, right - left + 1);
      3 = Math.max(      3,     3 -    0 + 1);
      3 = Math.max(3, 4);
      longest = 4;
right++ -> 4
```
```
longest = 4;
left = 0;
right = 4;
zeroes = 1;
[1, 0, 1, 1, 0]
 ^           ^
 l           r

while(right < nums.length)       
[r] == 0 .:. zeroes++ -> 2
zeroes == 0 enter while and shrink window
while(zeroes == 2)
{
    if(nums[left] == 0)
        zeroes--;
    left++;
}
[1, 0, 1, 1, 0]
 ^           ^
 l           r
[l] != 0  .:. l++ -> 1
[1, 0, 1, 1, 0]
    ^        ^
    l        r
[l] == 0 .:. zeroes-- -> 1
l++ -> 2
[1, 0, 1, 1, 0]
       ^     ^
       l     r
zeroes != 2 .:. exit while

longest = Math.max(longest, right - left + 1);
      4 = Math.max(      4,     4 -    2 + 1);
      4 = Math.max(4, 3);
      longest = 4;
right++ -> 5   //done
```
## #414 Third maximun number
- Given [int] return 3rd distinct maximum number in [int]. 
- If 3rd maximun doesn't exist, return maximun number
```
in : [3, 2, 1]
out : 1
- First distinct max is 3
- Second distinct max is 2
- Third distinct max is 1
```
```
in : [1, 2]
out: 2
- First distinct max is 2
- Second distinct max is 1
- Third distinct max doesn't exist, reeturn max -> 2
```
```
in : [2, 2, 3, 1]
out: 1
- First distinct max is 3
- Second distinct max is 2(both 2s are counted as same)
- Third distinct max is 1
```
### Approach 1: Sorting
- Time: O(N log N)
- Space: O(1)
```java
class Solution {
    public int thirdMax(int[] nums) {
        Arrays.sort(nums);
        for(int index = 0; index < nums.length/2; ++index)
        {
            int temp = nums[index];
            nums[index] = nums[nums.length - 1 - index];
            nums[nums.length - 1 - index] = temp;
        }
        int elem_count = 1;
        int prev_elem = nums[0];
        for(int index = 1; index < nums.length; ++index)
        {
            if(nums[index] != prev_elem)
            {
                elem_count++;
                prev_elem = nums[index];
            }
            if(elem_count == 3)
                return nums[index];
        }
        return nums[0];  //reached end of loop return max element since no 3rd max found
    }
}
```
- Sort arr
- Reverse arr to be in non-increasing order
- Iterate arr from 1 - length
- Increase count++ for ever unique element found.
- If end of [int] reached, return [0]/max value since there is no 3rd max element

### Approach 2: Min heap
- Time: O(N)
- Space: O(1)
```java
class Solution {
    public int thirdMax(int[] nums) {
        PriorityQueue<Integer> min_heap = new PriorityQueue<>();
        Set<Integer> taken = new HashSet<Integer>();
        for(int i = 0; i < nums.length; i++)
        {
            if(taken.contains(nums[i]))
                continue;
            if(min_heap.size() == 3)
            {
                if(min_heap.peek() < nums[i])
                {
                    taken.remove(min_heap.poll());
                    min_heap.add(nums[i]);
                    taken.add(nums[i]);
                }
            }
            else
            {
                min_heap.add(nums[i]);
                taken.add(nums[i]);
            }
        }
        if(min_heap.size() == 1)
            return min_heap.peek();
        else if(min_heap.size() == 2)
        {
            int first_num = min_heap.poll();
            return Math.max(first_num, min_heap.peek());
        }
        return min_heap.peek();
    }
}
```
- Use a min heap to track the 3 greatest values seen while iterating [int]
- When new value is found > the 3 in heap, remove smallest from heap and insert new value
- Heap should only have 3 numbers. This way the min value in heap will be 3rd max after iteration
- If there aren't 3 values, then return max value in heap. 
- Set is used to make check if current val already in heap

### Approach 3: Ordered set
- Time: O(N)
- Space: O(1)
```java
class Solution {
    public int thirdMax(int[] nums) {
        TreeSet<Integer> sorted_nums = new TreeSet<Integer>();
        for(int num: nums)
        {
            if(sorted_nums.contains(num))
                continue;
            if(sorted_nums.size() == 3)
            {
                if(sorted_nums.first() < num)
                {
                    sorted_nums.pollFirst();
                    sorted_nums.add(num);
                }
            }
            else
                sorted_nums.add(num);
        }
        if(sorted_nums.size() == 3)
            return sorted_nums.first();
        return sorted_nums.last();
    }
}
```
- Similar to previous approach, except use set to keep track of values instead of heap
### Approach 4: 3 pointers
- Time: O(N)
- Space: O(1)
```java
class Solution {
    public int thirdMax(int[] nums) {
        long first_max = Long.MIN_VALUE;
        long second_max = Long.MIN_VALUE;
        long third_max = Long.MIN_VALUE;
        for(int num : nums)
        {
            if(first_max == num || second_max == num || third_max == num)
                continue;
            if(first_max <= num)
            {
                third_max = second_max;
                second_max = first_max;
                first_max = num;
            }
            else if(second_max <= num)
            {
                third_max = second_max;
                second_max = num;
            }
            else if(third_max <= num)
                third_max = num;
        }
        if(third_max == Long.MIN_VALUE)
        {
            int ans = (int) first_max;
            return ans;
        }
        int ans = (int) third_max;
        return ans;
    }
}
```
## #448 Find all numbers disappeared in an array
- Given [int] of n ints where [i] is in range [1, n], return array of all ints in range [1,n]
  that are not in [int]
```
in: [4, 3, 2, 7, 8, 2, 3, 1]
out: [5, 6]

in: [1, 1]
out: [2]
```
### Approach 1: Use hash
- Time: O(N)
- Space: O(N)
```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        //hash keeps track of items in arr. Set can be used as well
        HashMap<Integer, Boolean> hash = new HashMap<Integer, Boolean>();
        for(int i = 0; i < nums.length; i++) //add to hash
            hash.put(nums[i], true);
        List<Integer> result = new LinkedList<Integer>();
        //iterate from 1-n, adding numbers to result which aren't in hash
        for(int i = 1; i <= nums.length; i++)
            if(!hash.containsKey(i))
                result.add(i);
        return result;
    }
}
```
- Iterate, adding all numbers in [int] to hash or set
- Iterate numbers [1,n] checking if [i] in hash/set.
    - If [i] is not in hash or set then it is missing .:. add to result

### Approach 2: In place modification
Time: O(N)
Space: O(1)
```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        for(int i = 0; i < nums.length; i++)
        {
            int new_index = Math.abs(nums[i]) - 1;
            //assign new index to 
            if(nums[new_index] > 0)
                nums[new_index] *= -1;  //negate [i] to mark it as found
        }
        List<Integer> result = new LinkedList<Integer>();
        //iterate [1,n], the positive ones are the missing numbers
        for(int i = 1; i <= nums.length; i++)
            if(nums[i - 1] > 0)
                result.add(i);
        return result;
    }
}
```
- Iterate [int]
- For ea [i], mark element at corresponding location negative
    - new_index is index where [i] would be if sorted: [i - 1]
    - if value at [i] is +, make it - to mark it as found
- Iterate [1,n], +[i] elements are the missing ones