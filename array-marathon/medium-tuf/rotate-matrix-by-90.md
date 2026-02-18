# Rotate matrix by 90 degrees

Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.

The rotation must be done in place, meaning the input 2D matrix must be modified directly.

## Brute Force

- Use Dummy matrix
- Take first row, place in last matrix and so on

> Time Complexity: `O(m*n)`
>
> Space Complexity: O(m*n)


## optimal Approach

- Take transpose of the matrix
  - `swap(matrix[i][j], matrix[j][i])`, until j<i
- Take reverse for every row

```cpp
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //transpose
        for(int row = 0; row < n; row++){
            for(int col = 0; col < row; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        //reverse each row
        for(int row = 0; row < n; row++){
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};
```

> Time Complexity: `O(m*n)`
>
> Space Complexity: O(1)