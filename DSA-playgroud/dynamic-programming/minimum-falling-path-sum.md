# Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Practice [Link](https://leetcode.com/problems/minimum-falling-path-sum/description/)

## Recursive

```cpp
class Solution {
public:

    int findMinFallingPath(vector<vector<int>>& matrix, int i, int j)
    {
        if(i==matrix.size()-1)
            return matrix[i][j];

        int left=INT_MAX, bottom, right=INT_MAX;
        if(j>0)
            left = findMinFallingPath(matrix, i+1, j-1);

        bottom = findMinFallingPath(matrix, i+1, j);

        if(j<matrix.size()-1)
            right = findMinFallingPath(matrix, i+1, j+1);

        return matrix[i][j] + min({left, bottom, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int minSum = INT_MAX;
        for(int col=0;col<n;col++)
        {
            minSum = min(minSum, findMinFallingPath(matrix, 0, col));
        }
        return minSum;
    }
};
```

> TLE - overlapping cases

## Memoized


> Note: here the memo vector had to be initialized with -10000, since constraints say `-100 <= matrix[i][j] <= 100`, which if initialized to -1 would give TLE as -1 could be a valid answer.

```cpp
class Solution {
public:

    int findMinFallingPath(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &memo)
    {
        if(i==matrix.size()-1)
            return matrix[i][j];

        if(memo[i][j] != -10000)
            return memo[i][j];

        int left=INT_MAX, bottom, right=INT_MAX;
        if(j>0)
            left = findMinFallingPath(matrix, i+1, j-1, memo);

        bottom = findMinFallingPath(matrix, i+1, j, memo);

        if(j<matrix.size()-1)
            right = findMinFallingPath(matrix, i+1, j+1, memo);

        return memo[i][j] = matrix[i][j] + min({left, bottom, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, -10000));
        int minSum = INT_MAX;
        for(int col=0;col<n;col++)
        {
            minSum = min(minSum, findMinFallingPath(matrix, 0, col, memo));
        }
        return minSum;
    }
};
```