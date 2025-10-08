## #1346 Check if N and Its double exist
- Given [int] check if there exist 2 different indices i and j such that:
    - i != j
    - 0 <= i, j < arr.lengh
    - arr[i] == 2 * arr[j]
### Approach
- Use a set to keep track of previously seen values
- For each value check if [i]*2 or [i]/2 exist in set
- Since [int], check that [i]%2 == 0 to make sure it is a whole number then check if [i]/2 in set
bc if [i]/2 is not a whole number then it won't be in set since there are only whole numbers in [int]
```java
class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> seen = new HashSet<>();
        for(int i = 0; i < arr.length; i++)
        {
            if(seen.contains(2 * arr[i]) || (arr[i] % 2 == 0 && seen.contains(arr[i]/2)))
                return true;
            seen.add(arr[i]);
        }
        return false;
    }
}
```
## #941 Valid mountain array
- Given [int], return true if it is a valid mountain array
- Valid mountain array:
    - arr.length >= 3
    - [0, 2, 3, 4, 5, 2, 1, 0]
    - [0, 3, 2, 1]
- NOT VALID
    - [0, 2, 3, 3, 5, 2, 1, 0]
    - [2, 1]
    - [3, 5, 5]
```java
class validMountain {
    public boolean valid_mountain(int[] arr) {
        boolean decline_found = false;
        if(arr.length < 3 || arr[0] > arr[1]) //check arr doesn't start in decline
            return false;
        for(int i = 1; i < arr.length; i++)
        {
            if(arr[i] == arr[i - 1])  //check that values do not repeat
                return false;
            if(!decline_found && arr[i] < arr[i - 1]) //decline found
                decline_found = true;
            if(decline_found && arr[i] > arr[i - 1]) //check arr not in incline again
                return false;
        }
        return decline_found;
    }
}
```
### Strategy
- Check that length of arr is > 3
- Check that arr doesn't start in decline since arr must start in incline 
```
[0, 2, 3, 4, 5, 2, 1, 0]
```
- Iterate:
    - Check that [i] != [i - 1] to make sure values do not repeat. If values repeat, it is not valid
    - Look for start of decline of mountain. decline_found = false is used to track start of decline.
      If, decline_found is false and [i] < arr[i - 1] then this is the start of decline. Set 
      decline_found = true
    - Having found the decline check that values stay in decline
- If reached end of array, means it is a valid mountain array. 