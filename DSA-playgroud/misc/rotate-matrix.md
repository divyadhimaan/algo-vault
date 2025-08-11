# Rotate Matrix

Practice [here](https://leetcode.com/problems/rotate-image/description/)

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

## Simulation
```cpp
class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void reverseByRows(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseByRows(matrix);
    }
};
```