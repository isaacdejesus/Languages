## # 485 Max consecutive ones
- Given a binary array of containing only 0's and 1's, return max number of consecutive 1's in array
```java
public static int f(int[] nums)
{
    int max_count = 0;
    int current_count = 0;
    for(int i = 0; i < nums.length; i++)
    {
        if(nums[i] == 0)
        {
            max_count = Math.max(max_count, current_count);
            current_count = 0;
        }
        else
            current_count++;
    }
    return Math.max(max_count, current_count);
}
```
## # 1295 Find numbers with even number of digits
- Given arr of ints, return how many contain an even number of digits
### Approach 1: Extract digits to determine if even
```java
//extract digits from each number to determine if even
public static boolean has_even_digits_2(int num)
{
    int digit_count = 0;
    while(num != 0)
    {
        digit_count++;
        num/=10;
    }
    return (digit_count & 1) == 0;
}
//extract digits from each number to determine if even
public static boolean has_even_digits_1(int num)
{
    int digit_count = 0;
    while(num != 0)
    {
        digit_count++;
        num = num / 10;
    }
        if(digit_count % 2 == 0)
            return true;
        else 
            return false;
    }
public static int f1(int[] nums)
{
    int even_digit_count = 0;
    for(int num: nums) 
    {
        if(has_even_digits_1(num))
            even_digit_count++;
    }
    return even_digit_count;
}
```
- Note: return condition uses *bitwise AND* to check if number is even/odd. If least significant bit of
  a number is 1 then number is odd.
```java
public static boolean has_even_digits_2(int num)
{
    int digit_count = 0;
    while(num != 0)
    {
        digit_count++;
        num/=10;
    }
    return (digit_count & 1) == 0;  //use &1 to determine if even or odd.
}
```
### Approach 2: Convert number to string then use length to determine if even
```java
//convert numbers to string and calc length to determine if even
public static int f2(int[] nums)
{
    int even_digit_count = 0;
    for(int num: nums)
    {
        int length = String.valueOf(num).length();
        if(length % 2 == 0)
            even_digit_count++;
    }
    return even_digit_count;
}
```
### Approach 3: use log10 to calc length of number then determine if even
```java
//use log10 to compute length of number then determine if even
public static int f3(int[] nums)
{
    int even_digit_count = 0;
    for(int num: nums)
    {
        int digit_count = (int) Math.floor(Math.log10(num)) + 1;
        if(digit_count % 2 == 0)
            even_digit_count++;
    }
    return even_digit_count;
}
```
## # 977 Sq of sorted arr
- Given an arr of sorted ints, return arr of sq values sorted
### O(nlogn) solution sq values then sort resulting arr
```java
public static int[] sorted_sq1(int[] nums)
{
    int arr_length = nums.length;
    int[] ans = new int[arr_length];
    for(int i = 0; i < arr_length; i++)
        ans[i] = nums[i] * nums[i];
    Arrays.sort(ans);  //O(nlogn) due to sort
    return ans;
}
```
### Optimal: 2 pointers
- Since array is sorted iterate arr from outside in since largest positive and negative values will
  be on the outside: 
  [-4, -1, 0, 3, 10]
    l            r
- Compare int at pointer, taking largest, calc sq value and adding at end of result arr/in this case i
```java
public static int[] sorted_sq2(int[] nums)
{
    int arr_length = nums.length;
    int[] result = new int[arr_length];
    int left = 0;
    int right = arr_length - 1;
    for(int i = arr_length - 1; i >= 0; i--) //insert at the back of arr
    {
        int sq;
        if(Math.abs(nums[left]) < Math.abs(nums[right]))
        {
            sq = nums[right];
            right--;
        }
        else
        {
            sq = nums[left];
            left++;
        }
        result[i] = sq * sq;
    }
    return result;
}
```
