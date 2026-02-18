# Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0. You must do it in place.

## Brute Force

- store rows and cols having zeroes
- Mark zeroes accordingly
- Not be in in-place

> Time Complexity: `O(m*n)`
>
> Space Complexity: O(m+n)

## Optimal Approach

- Use variables to store if first row or first col contains zero
- iterate through matrix and if zero found, mark first row ele and first col ele as zero
- Using first row and first col, mark whole row and col zeroes
- now using variables for firstRow and firstCol, mark zeroes in first row or col

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int isColOneZero = false, isRowOneZero = false;

        // identify if first row or first col has zeroes
        for(int row = 0; row < m; row++){
            if(matrix[row][0] == 0){
                isColOneZero = true;
                break;
            }
        }
        for(int col = 0; col < n; col++){
            if(matrix[0][col] == 0){
                isRowOneZero = true;
                break;
            }
        }


        // identify other zeroes
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][col] == 0){
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        // mark matrix elements to zeroes based on markers in first row or col
        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){
                if(matrix[row][0] == 0 || matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
            }
        }

        //mark first row or col based on special markers
        if(isColOneZero){
            for(int row = 0; row < m; row++){
                matrix[row][0] = 0;
            }
        }
        if(isRowOneZero){
            for(int col = 0; col < n; col++){
                matrix[0][col] = 0;
            }
        }
    }
};
```


> Time Complexity: `O(m*n)`
>
> Space Complexity: O(1)