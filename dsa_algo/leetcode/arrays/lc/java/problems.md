## Max consecutive ones
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
## Find numbers with eveen number of digits
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
