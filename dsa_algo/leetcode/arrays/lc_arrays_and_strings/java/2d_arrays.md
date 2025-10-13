## #498 Diagonal traverse
- Given an m x n matrix, return an arr, of all elements of matrix in diagonal order
- See problem on lc for diagram
```
in: [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
out: [1, 2, 4, 7, 5, 3, 6, 8, 9]
```
```
in: [[1, 2],
     [3, 4]]
out: [1, 2, 3, 4]
```
### Approach 1: Diagonal iteration and reversal
- Time: O(rows * cols)
- Space: O(min(rows, cols))
```java
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if(matrix == null || matrix.length == 0)
            return new int[0];
        int matrix_rows = matrix.length;
        int matrix_cols = matrix[0].length;
        int[] result = new int[matrix_rows*matrix_cols];
        int k = 0;
        ArrayList<Integer> intermediate = new ArrayList<Integer>();
        for(int diagonal = 0; diagonal < matrix_rows + matrix_cols - 1; diagonal++)
        {
            intermediate.clear();
            int r = diagonal < matrix_cols ? 0 : diagonal - matrix_cols + 1;
            int c = diagonal < matrix_cols ? diagonal : matrix_cols - 1;
            while(r < matrix_rows && c > -1)
            {
                intermediate.add(matrix[r][c]);
                ++r;
                --c;
            }
            if(diagonal % 2 == 0)
                Collections.reverse(intermediate);
            for(int i = 0 ; i < intermediate.size(); i++)
                result[k++] = intermediate.get(i);
        }
        return result;
    }
}
```
```
    [1, 2, 3]
    [4, 5, 6]
    [7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [_,_,_,_,_,_,_,_,_]
k = 0;
intermediate = [];
```
```java

for(int diagonal = 0; diagonal < matrix_rows + matrix_cols - 1; diagonal++)
```
```
for(int diagonal = 0; diagonal < matrix_rows + matrix_cols - 1; diagonal++)
                                           3 + 3 - 1
[1, 2, 3]  
[4, 5, 6]
[7, 8, 9]    there are 5 diagonals
```
```
    [1, 2, 3]
    [4, 5, 6]
    [7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [_,_,_,_,_,_,_,_,_]
k = 0;
intermediate = [];

diagonal : 0 < 5, Yes
r = diagonal < matrix_cols ? 0 : diagonal - matrix_cols + 1;
           0 <           3 ? 0 :        0 - 3 + 1
           0 <           3 ? 0 :        0 - 4
r = 0
c = diagonal < matrix_cols ? diagonal : matrix_cols - 1;
           0 <           3 ?        0 :           3 - 1;
           0 <           3 ?        0 :           3 - 1;
c = 0
```
```java
while(r < matrix_rows && c > -1)
{
    intermediate.add(matrix[r][c]);
    ++r;
    --c;
}
```
```
    [1, 2, 3]
    [4, 5, 6]
    [7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [_,_,_,_,_,_,_,_,_]
k = 0;
intermediate = [];
diagonal : 0
r = 0
c = 0

(r < matrix_rows && c > - 1)
(0 <           3 && 0 > - 1) : Yes, enter while
intermediate.add[0][0];  -> [0]
r++ -> 1
c-- -> -1
c < -1 .:. exit while
```
```java
if(diagonal % 2 == 0)
    Collections.reverse(intermediate);
```
```
(diagonal % 2 == 0)
        0 % 2 == 0 : Yes, reverse arr
```
```java
for(int i = 0 ; i < intermediate.size(); i++)
    result[k++] = intermediate.get(i);
```
```
insert diagonal into result arr using k as insert index
[1]
```
```
    [1, 2, 3]
    [4, 5, 6]
    [7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,_,_,_,_,_,_,_,_]
k = 1;
intermediate = [];
```
```
diagonal : 1 < 5, Yes
r = diagonal < matrix_cols ? 0 : diagonal - matrix_cols + 1;
           1 <           3 ? 0 :        1 - 3 + 1
           1 <           3 ? 0 :        1 - 4
r = 0
c = diagonal < matrix_cols ? diagonal : matrix_cols - 1;
           1 <           3 ?        1 :           3 - 1;
           1 <           3 ?        1 :           3 - 1;
c = 1
```
```java
while(r < matrix_rows && c > -1)
{
    intermediate.add(matrix[r][c]);
    ++r;
    --c;
}
```
```
    [1, 2, 3]
    [4, 5, 6]
    [7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,_,_,_,_,_,_,_,_]
k = 1;
intermediate = [];
diagonal : 1
r = 0
c = 1

(r < matrix_rows && c > - 1)
(0 <           3 && 1 > - 1) : Yes, enter while
intermediate.add[0][1];  -> [2]
r++ -> 1
c-- -> 0 
intermediate.add[1][0];  -> [2, 4]
r++ -> 2
c-- -> -1
c < 0 .:. exit while
```
```java
if(diagonal % 2 == 0)
    Collections.reverse(intermediate);
```
```
(diagonal % 2 == 0)
        0 % 2 == 0 : No, continue
```
```java
for(int i = 0 ; i < intermediate.size(); i++)
    result[k++] = intermediate.get(i);
```
```
insert diagonal into result arr using k as insert index
[1, 2, 4]
```
```
    [1, 2, 3]
    [4, 5, 6]
    [7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,2,4,_,_,_,_,_,_]
k = 3;
intermediate = [];
```
```
diagonal : 2 < 5, Yes
r = diagonal < matrix_cols ? 0 : diagonal - matrix_cols + 1;
           2 <           3 ? 0 :        2 - 3 + 1
           2 <           3 ? 0 :        2 - 4
r = 0
c = diagonal < matrix_cols ? diagonal : matrix_cols - 1;
           2 <           3 ?        2 :           3 - 1;
           2 <           3 ?        2 :           3 - 1;
c = 2
```
```java
while(r < matrix_rows && c > -1)
{
    intermediate.add(matrix[r][c]);
    ++r;
    --c;
}
```
```
    [1, 2, 3]
    [4, 5, 6]
    [7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,2,4,_,_,_,_,_,_]
k = 3;
intermediate = [];
diagonal : 2
r = 0
c = 2

(r < matrix_rows && c > - 1)
(0 <           3 && 2 > - 1) : Yes, enter while
intermediate.add[0][2];  -> [3]
r++ -> 1
c-- -> 1 
intermediate.add[1][1];  -> [3, 5]
r++ -> 2
c-- -> 0 
intermediate.add[2][0];  -> [3, 5, 7]
r++ -> 3
c-- -> -1
c < 0 .:. exit while
```
```java
if(diagonal % 2 == 0)
    Collections.reverse(intermediate);
```
```
(diagonal % 2 == 0)
        2 % 2 == 0 : Yes, reverse intermediate

[3, 5, 7] -> [7, 5, 3]
```
```java
for(int i = 0 ; i < intermediate.size(); i++)
    result[k++] = intermediate.get(i);
```
```
insert diagonal into result arr using k as insert index
[1, 2, 4, 7, 5, 3]
```
### Approach 2: Simulation
- Time: O(rows * cols)
- Space: O(1)
```java
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if(matrix == null || matrix.length == 0)
            return new int[0];
        int matrix_rows = matrix.length;
        int matrix_cols = matrix[0].length;
        int[] result = new int[matrix_rows*matrix_cols];
        int r = 0;
        int row = 0;
        int col = 0;
        int direction = 1;
        while(row < matrix_rows && col < matrix_cols)
        {
            result[r++] = matrix[row][col];
            int new_row = row + (direction == 1 ? -1 : 1);
            int new_col = col + (direction == 1 ? 1 : -1);
            if(new_row < 0 || new_row == matrix_rows || new_col < 0 || new_col == matrix_cols)
            {
                if(direction == 1)
                {
                    row += (col == matrix_cols - 1 ? 1 : 0);
                    col += (col < matrix_cols - 1 ? 1 : 0);
                }
                else{
                   col += (row == matrix_rows -1 ? 1 : 0);
                   row += (row < matrix_rows -1 ? 1 : 0);
                }
                direction = 1 - direction;
            }
            else {
                row = new_row;
                col = new_col;
            }
        }
        return result;
    }
}
```
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [_,_,_,_,_,_,_,_,_];
r = 0;
row = 0;
col = 0
direction = 1
```
```java
while(row < matrix_rows && col < matrix_cols)
```
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [_,_,_,_,_,_,_,_,_];
r = 0;
row = 0;
col = 0
direction = 1
while(row < matrix_rows && col < matrix_cols)
        0 <           3 &&   0 < 3 : Yes, enter while
```
```java
result[r++] = matrix[row][col];
int new_row = row + (direction == 1 ? -1 : 1);
int new_col = col + (direction == 1 ? 1 : -1);
if(new_row < 0 || new_row == matrix_rows || new_col < 0 || new_col == matrix_cols)
```
```
result[r++] = matrix[row][col];
result[0] = matrix[0][0]
result[0] = [1]
new_row = row + (direction == 1 ? -1 : 1);
        =   0 + (        1 == 1 ? -1 : 1)
        = 0 + -1
new_row = -1
new_col = col + (direction == 1 ? 1 : -1);
        =   0 + (        1 == 1 ? 1 : -1)
        =   0 + 1
new_col = 1
.:.
new_row = -1
new_col = 1
if(new_row < 0 || new_row == matrix_rows || new_col < 0 || new_col == matrix_cols)
  (     -1 < 0 ||      -1 ==           3 ||       1 < 0 ||       1 ==           3) : Yes, new_row < 0, enter if
```
```java
if(direction == 1)
{
    row += (col == matrix_cols - 1 ? 1 : 0);
    col += (col < matrix_cols - 1 ? 1 : 0);
}
else{
        col += (row == matrix_rows -1 ? 1 : 0);
        row += (row < matrix_rows -1 ? 1 : 0);
    }
direction = 1 - direction;
```
```
if(direction == 1) : Yes, enter if
row += (col == matric_cols - 1 ? 1 : 0)
  0 += (  0 ==           3 - 1 ? 1 : 0)
  0 += (  0 ==           2     ? 1 : 0)
  0 += 0
  row = 0

col += (col < matric_cols - 1 ? 1 : 0)
  0 += (  0 <           3 - 1 ? 1 : 0)
  0 += (  0 <           2     ? 1 : 0)
  0 += 1
  col = 1
```
```
direction = 1 - direction;
direction = 1 - 1 = 0
```
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,_,_,_,_,_,_,_,_];
r = 1;
row = 0;
col = 1
direction = 0
while(row < matrix_rows && col < matrix_cols)
        0 <           3 &&   1 < 3 : Yes, enter while
```
```
result[r++] = matrix[row][col];
result[1] = matrix[0][1]
result[1] = [1, 2]
new_row = row + (direction == 1 ? -1 : 1);
        =   0 + (        0 == 1 ? -1 : 1)
        = 0 + 1
new_row = 1
new_col = col + (direction == 1 ? 1 : -1);
        =   1 + (        0 == 1 ? 1 : -1)
        =   1 + -1
new_col = 0
.:.
new_row = 1
new_col = 0
if(new_row < 0 || new_row == matrix_rows || new_col < 0 || new_col == matrix_cols)
  (      1 < 0 ||       1 ==           3 ||       0 < 0 ||       0 ==           3) : No, exit if
```
```java
else {
    row = new_row;
    col = new_col;
}
```
```
row = new_row
row = 1
col = new_col
col = 0
```
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,2,_,_,_,_,_,_,_];
r = 2;
row = 1;
col = 0
direction = 0
while(row < matrix_rows && col < matrix_cols)
        1 <           3 &&   0 < 3 : Yes, enter while
```
```
result[r++] = matrix[row][col];
result[2] = matrix[1][0]
result[2] = [1, 2, 4]
new_row = row + (direction == 1 ? -1 : 1);
        =   1 + (        0 == 1 ? -1 : 1)
        = 1 + -1
new_row = 0
new_col = col + (direction == 1 ? 1 : -1);
        =   0 + (        0 == 1 ? 1 : -1)
        =   0 + -1
new_col = - 1 
.:.
new_row = 0
new_col = -1
if(new_row < 0 || new_row == matrix_rows || new_col < 0 || new_col == matrix_cols)
  (      1 < 0 ||       1 ==           3 ||       0 < 0 ||       0 ==           3) : Yes, new_col < 0, enter if
```
```java
if(direction == 1)
{
    row += (col == matrix_cols - 1 ? 1 : 0);
    col += (col < matrix_cols - 1 ? 1 : 0);
}
else{
    col += (row == matrix_rows -1 ? 1 : 0);
    row += (row < matrix_rows -1 ? 1 : 0);
}
direction = 1 - direction;
```
```
direction != 1 .:. enter else
col += (row == matrix_rows - 1 ? 1 : 0);
  0 += (  1 ==           3 - 1 ? 1 : 0)
  0 += (  1 ==           2     ? 1 : 0)
  0 += 0
col = 0
row += (row < matrix_rows - 1 ? 1 : 0);
  1 += (  1 <           3 - 1 ? 1 : 0)
  1 += (  1 <           2     ? 1 : 0>)
  1 += 1
row = 2
direction = 1 - 0 = 1
```
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,2,4,_,_,_,_,_,_];
r = 3;
row = 2;
col = 0
direction = 1
while(row < matrix_rows && col < matrix_cols)
        2 <           3 &&   0 < 3 : Yes, enter while
```
```
result[r++] = matrix[row][col];
result[3] = matrix[2][0]
result[3] = [1, 2, 4, 7]
new_row = row + (direction == 1 ? -1 : 1);
        =   2 + (        1 == 1 ? -1 : 1)
        = 2 + -1
new_row = 1
new_col = col + (direction == 1 ? 1 : -1);
        =   0 + (        1 == 1 ? 1 : -1)
        =   0 + 1
new_col =  1 
.:.
new_row = 1
new_col = 1
if(new_row < 0 || new_row == matrix_rows || new_col < 0 || new_col == matrix_cols)
  (      1 < 0 ||       1 ==           3 ||       0 < 0 ||       0 ==           3) : No, skip if

```
```java
else {
    row = new_row;
    col = new_col;
}
```
```
row = new_row
row = 1
col = new_col 
col = 1
```
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,2,4,7,_,_,_,_,_];
r = 4;
row = 1;
col = 1
direction = 1
while(row < matrix_rows && col < matrix_cols)
        1 <           3 &&   1 < 3 : Yes, enter while
```
```
result[r++] = matrix[row][col];
result[4] = matrix[1][1]
result[4] = [1, 2, 4, 7, 5]
new_row = row + (direction == 1 ? -1 : 1);
        =   1 + (        1 == 1 ? -1 : 1)
        = 1 + -1
new_row = 0
new_col = col + (direction == 1 ? 1 : -1);
        =   1 + (        1 == 1 ? 1 : -1)
        =   1 + 1
new_col =  2 
.:.
new_row = 0
new_col = 2
if(new_row < 0 || new_row == matrix_rows || new_col < 0 || new_col == matrix_cols)
  (      1 < 0 ||       1 ==           3 ||       0 < 0 ||       0 ==           3) : No, skip if
```
```java
else {
    row = new_row;
    col = new_col;
}
```
```
row = new_row
row = 0
col = new_col 
col = 2
```
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,2,4,7,5,_,_,_,_];
r = 5;
row = 0;
col = 2
direction = 1
while(row < matrix_rows && col < matrix_cols)
        0 <           3 &&   2 < 3 : Yes, enter while
```
```
result[r++] = matrix[row][col];
result[5] = matrix[0][2]
result[5] = [1, 2, 4, 7, 5, 3]
new_row = row + (direction == 1 ? -1 : 1);
        =   0 + (        1 == 1 ? -1 : 1)
        = 0 + -1
new_row = -1 
new_col = col + (direction == 1 ? 1 : -1);
        =   2 + (        1 == 1 ? 1 : -1)
        =   2 + 1
new_col =  3 
.:.
new_row = -1
new_col = 3
if(new_row < 0 || new_row == matrix_rows || new_col < 0 || new_col == matrix_cols)
  (      1 < 0 ||       1 ==           3 ||       0 < 0 ||       0 ==           3) : Yes, enter if
```
```java
if(direction == 1)
{
    row += (col == matrix_cols - 1 ? 1 : 0);
    col += (col < matrix_cols - 1 ? 1 : 0);
}
else{
    col += (row == matrix_rows -1 ? 1 : 0);
    row += (row < matrix_rows -1 ? 1 : 0);
}
direction = 1 - direction;
```
```
direction : 1 .:. enter if
row += (col == matrix_cols - 1 ? 1 : 0);
 0 += (  2 ==           3 - 1 ? 1 : 0)
 0 += (  2 ==           2     ? 1 : 0)
 0 += 1
row = 1
col += (col < matrix_cols - 1 ? 1 : 0);
  2 += (  3 <           3 - 1 ? 1 : 0)
  2 += (  3 <           2     ? 1 : 0)
  2 += 0
col = 2
direction = 1 - 1  = 0
```
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,2,4,7,5,3,_,_,_];
r = 6;
row = 1;
col = 2
direction = 0
while(row < matrix_rows && col < matrix_cols)
        1 <           3 &&   2 < 3 : Yes, enter while
```
```
result[r++] = matrix[row][col];
result[6] = matrix[1][2]
result[6] = [1, 2, 4, 7, 5, 3, 6]
new_row = row + (direction == 1 ? -1 : 1);
        =   1 + (        1 == 1 ? -1 : 1)
        = 1 + 1
new_row = 2 
new_col = col + (direction == 1 ? 1 : -1);
        =   2 + (        1 == 1 ? 1 : -1)
        =   2 + -1
new_col =  1 
.:.
new_row = 2
new_col = 1
if(new_row < 0 || new_row == matrix_rows || new_col < 0 || new_col == matrix_cols)
  (      1 < 0 ||       1 ==           3 ||       0 < 0 ||       0 ==           3) : No, skip if
```
```java
else {
    row = new_row;
    col = new_col;
    }
```
```
row = new_row;
row = 2
col = new_col;
col = 1
```
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,2,4,7,5,3,6,_,_];
r = 7;
row = 2;
col = 1
direction = 0
while(row < matrix_rows && col < matrix_cols)
        2 <           3 &&   1 < 3 : Yes, enter while
```
```
result[r++] = matrix[row][col];
result[7] = matrix[2][1]
result[7] = [1, 2, 4, 7, 5, 3, 6, 8]
new_row = row + (direction == 1 ? -1 : 1);
        =   2 + (        1 == 1 ? -1 : 1)
        = 2 + 1
new_row = 3 
new_col = col + (direction == 1 ? 1 : -1);
        =   1 + (        1 == 1 ? 1 : -1)
        =   1 + -1
new_col =  0 
.:.
new_row = 3
new_col = 0
if(new_row < 0 || new_row == matrix_rows || new_col < 0 || new_col == matrix_cols)
  (      1 < 0 ||       1 ==           3 ||       0 < 0 ||       0 ==           3) : Yes, new_row == matrix_rows, enter if
```
```java
if(direction == 1)
{
    row += (col == matrix_cols - 1 ? 1 : 0);
    col += (col < matrix_cols - 1 ? 1 : 0);
}
else{
    col += (row == matrix_rows -1 ? 1 : 0);
    row += (row < matrix_rows -1 ? 1 : 0);
}
direction = 1 - direction;
```
```
direction : 0 .:. enter else
col += (row == matrix_rows -1 ? 1 : 0);
  1 += (  2 ==           3 -1 ? 1 : 0)
  1 += (  2 ==           2    ? 1 : 0)
  1 += 1
col = 2
row += (row < matrix_rows -1 ? 1 : 0);
  2 += (  2 <           3 - 1 ? 1 : 0)
  2 += 0
row = 2
direction = 1 - 0 = 1
```
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,2,4,7,5,3,6,8,_];
r = 8;
row = 2;
col = 2
direction = 1
while(row < matrix_rows && col < matrix_cols)
        2 <           3 &&   2 < 3 : Yes, enter while
```
```
result[r++] = matrix[row][col];
result[8] = matrix[2][2]
result[8] = [1, 2, 4, 7, 5, 3, 6, 8, 9]
new_row = row + (direction == 1 ? -1 : 1);
        =   2 + (        1 == 1 ? -1 : 1)
        = 2 + -1
new_row = 1 
new_col = col + (direction == 1 ? 1 : -1);
        =   2 + (        1 == 1 ? 1 : -1)
        =   2 + 1
new_col = 3 
.:.
new_row = 1
new_col = 3
if(new_row < 0 || new_row == matrix_rows || new_col < 0 || new_col == matrix_cols)
  (      1 < 0 ||       1 ==           3 ||       0 < 0 ||       0 ==           3) : Yes, new_col == matrix_cols, enter if
```
```java
if(direction == 1)
{
    row += (col == matrix_cols - 1 ? 1 : 0);
    col += (col < matrix_cols - 1 ? 1 : 0);
}
else{
    col += (row == matrix_rows -1 ? 1 : 0);
    row += (row < matrix_rows -1 ? 1 : 0);
}
direction = 1 - direction;
```
```
direction : 1 .:. enter if
row += (col == matrix_cols - 1 ? 1 : 0);
  2 += (  2 ==           3 - 1 ? 1 : 0)
  2 += 1
row = 3
col += (col < matrix_cols - 1 ? 1 : 0);
  2 += (  2 <           3 - 1 ? 1 : 0)
  2 += 1
col = 3
direction = 1 - 1 = 0
```
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
matrix_rows = 3;
matrix_cols = 3;
result = [1,2,4,7,5,3,6,8,9];
r = 9;
row = 3;
col = 3
direction = 0
while(row < matrix_rows && col < matrix_cols)
        3 <           3 &&   3 < 3 : No, exit while and return result


result = [1,2,4,7,5,3,6,8,9];
```
## #54 Spiral matrix
- Given matrix[m][n], return all elements in spiral order
```
in: [1  2  3
     4  5  6 
     7  8  9]
out: [1, 2, 3, 6, 9, 8, 7, 4, 5]
```
```
in : [1 2  3  4
      5 6  7  8
      9 10 11 12]
out: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
```
### Approach 1: Set boundaries
- Time: O(rows x cols)
- Space: O(1)
```java
class Solution {//Approach 1:  using boundaries
                //Time: O(Rows * Cols), Space: O(1)
    public List<Integer> spiralOrder(int[][] matrix)
    {
        List<Integer> result = new ArrayList<>();
        int matrix_rows = matrix.length;
        int matrix_cols = matrix[0].length;
        int up = 0;
        int left = 0;
        int right = matrix_cols - 1;
        int down = matrix_rows - 1;
        while(result.size() < matrix_rows * matrix_cols)
        {
            //traverse left -> right
            for(int col = left; col <= right; col++)
                result.add(matrix[up][col]);
            for(int row = up + 1; row <= down; row++)
                result.add(matrix[row][right]);
            if(up != down)
                for(int col = right - 1; col >= left; col--)
                    result.add(matrix[down][col]);
            if(left != right)
                for(int row = down - 1; row > up; row--)
                    result.add(matrix[row][left]);
            left++;
            right--;
            up++;
            down--;
        }
        return result;
    }
}
```
### Approach 2: mark visited cells
- Time: O(rows x cols)
- Space: O(1)
```java
class Solution {//Approach 2:  Mark visiteed cells
                //Time: O(Rows * Cols), Space: O(1)
    public List<Integer> spiralOrder(int[][] matrix)
    {
        List<Integer> result = new ArrayList<>();
        int matrix_rows = matrix.length;
        int matrix_cols = matrix[0].length;
        int visited = 101;
        int[][] directions = {{0, 1}, {1,0}, {0, -1}, {-1, 0}};
        int current_direction = 0;
        int change_direction = 0;
        int row = 0;
        int col = 0;
        result.add(matrix[0][0]);
        matrix[0][0] = visited;
        while(change_direction < 2)
        {
            while(
                row + directions[current_direction][0] >= 0 &&
                row + directions[current_direction][0] < matrix_rows &&
                col + directions[current_direction][1] >= 0 &&
                col + directions[current_direction][1] < matrix_cols &&
                matrix[row + directions[current_direction][0]][col + directions[current_direction][1]] != visited
            )
                {
                    change_direction = 0;
                    row = row + directions[current_direction][0];
                    col = col + directions[current_direction][1];
                    result.add(matrix[row][col]);
                    matrix[row][col] = visited;
                }
            change_direction = (current_direction + 1) % 4;
            change_direction++;
        }
        return result;
    }
}
```
## 118 Pascal's triangle
- Given an int numrows, return the first numrows of pascal's triangle
- In pascal's triangle, every number is the sum of the 2 numbers direectly above it. 
```
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1

in : numrows : 5
out : [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]

in : numrows : 1
out : [[1]]
```
### Approach: Dynamic programming
```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<List<Integer>>();
        triangle.add(new ArrayList<>());
        triangle.get(0).add(1);  //insert 0th row with single [1]
        //iterate to create rows [1, size] [1, 5]
        for(int row_num = 1; row_num < numRows; row_num++)
        {
            List<Integer> current_row = new ArrayList<>();
            List<Integer> prev_row = triangle.get(row_num - 1);
            current_row.add(1); //ea row has [0] in 0th index
            for(int i = 1; i < row_num; i++) //loop and calc current row
                current_row.add(prev_row.get(i - 1) + prev_row.get(i));
            current_row.add(1); //ea row ends with [0] in last index
            triangle.add(current_row); //add current row to triangle
        }
        return triangle;
    }
}
```
- Result is a 2d array called triangle.
- First/0th row contains a single [1]
- Iterate to create the remaining rows [1, length]
- For ea row: 
    - create a new empty arr
    - insert [1] start of arr
    - loop [1, size of row] calculating value for each [i]
    - insert [1] at end of arr
- insert newly created row to triangle