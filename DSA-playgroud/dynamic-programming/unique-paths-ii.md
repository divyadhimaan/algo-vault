# Unique Paths - II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

Practice [Link](https://leetcode.com/problems/unique-paths-ii/description/)


## Implementation

### A. Recursive Approach
```cpp
class Solution {
public:

    int findUniquePaths(vector<vector<int>>& obstacleGrid, int i, int j)
    {
        if(i<0 || j<0)
            return 0;

        if(obstacleGrid[i][j] == 1)
            return 0;

        if(i==0 && j==0 && obstacleGrid[i][j]==0)
            return 1;
        

        return findUniquePaths(obstacleGrid, i-1, j) + findUniquePaths(obstacleGrid, i, j-1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return findUniquePaths(obstacleGrid, m-1, n-1);
    }
};

```
> Time Limit Exceeded - Overlapping Cases


### B. Memoization

```cpp
class Solution {
public:

    int findUniquePaths(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>> &memo)
    {
        if(i<0 || j<0)
            return 0;

        if(memo[i][j]!= -1)
            return memo[i][j];

        if(obstacleGrid[i][j] == 1)
            return 0;

        if(i==0 && j==0 && obstacleGrid[i][j]==0)
            return 1;
        

        return memo[i][j] = findUniquePaths(obstacleGrid, i-1, j, memo) + findUniquePaths(obstacleGrid, i, j-1, memo);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> memo(m, vector<int>(n, -1));

        return findUniquePaths(obstacleGrid, m-1, n-1, memo);
    }
};
```

> Time Complexity - O(m * n)
> 
> Space Complexity - O((n-1)+(m-1)) + O(m * n)


### B. Tabulation Solution

```cpp
class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for(int i=1;i<m;i++)
            if(obstacleGrid[i][0] != 1)
                dp[i][0] = dp[i-1][0];

        for(int j=1;j<n;j++)
            if(obstacleGrid[0][j] != 1)
                dp[0][j] = dp[0][j-1];   

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[m-1][n-1];
    }
};

```

> Time Complexity - O(m * n)
> 
> Space Complexity - O(m * n)
 