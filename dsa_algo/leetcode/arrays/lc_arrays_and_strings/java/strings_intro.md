## #67 add binary
- Given 2 binary trings "a" and "b", return their sum as binary string
```
in : a = "11", b = "1"
out : "100"
```
```
in : a = "1010", b = "1011"
out : "10101"
```
### Approach 1: Bit by bit manipulation
- Time: O(max(N, M)) Where N and M are size of strings
- Space: O(Max(N, M)) 
```java
class Solution { //Approach 1: bit by bitr  computation
                 // Time: O(max(N, M)) Where N and M are size of strings
                 //Space: O(Max(N, M)) 
    public String addBinary(String a, String b) {
        int n = a.length();
        int m = b.length();
        if(n < m)
            return addBinary(b, a);
        StringBuilder result = new StringBuilder();
        int carry = 0;
        int j = m - 1;
        for(int i = n - 1; i > -1; i--)
        {
            if(a.charAt(i) == '1')
                ++carry;
            if(j > -1 && b.charAt(j--) == '1')
                ++carry;
            if(carry % 2== 1)
                result.append('1');
            else
                result.append('0');
            carry /= 2;
        }
        if (carry == 1)
            result.append('1');
        result.reverse();
        return result.toString();
    }
}
```

```
a = "1010"
b = "1011"
result = ""
carry = 0

```