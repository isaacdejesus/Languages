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