# Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Practice [Link](https://leetcode.com/problems/unique-paths/description/)


## Implementation

### A. Recursive Approach
```cpp
class Solution {
public:
    int uniquePathsUtil(int m, int n)
    {
        if(m==0 && n==0)
            return 1;
        
        if(m<0 || n<0)
            return 0;

        return uniquePathsUtil(m-1,n) + uniquePathsUtil(m,n-1);
    }
    int uniquePaths(int m, int n) {
        return uniquePathsUtil(m-1,n-1);
    }
};

```
> Time Limit Exceeded - Overlapping Cases


### B. Memoization

```cpp
class Solution {
public:
    int uniquePathsUtil(int m, int n, vector<vector<int>> &memo)
    {
        if(m==0 && n==0)
            return 1;
        
        if(m<0 || n<0)
            return 0;

        if(memo[m][n] != -1)
            return memo[m][n];

        return memo[m][n] = uniquePathsUtil(m-1,n, memo) + uniquePathsUtil(m,n-1, memo);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n,-1));
        return uniquePathsUtil(m-1,n-1, memo);
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
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,1));

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

```

> Time Complexity - O(m * n)
> 
> Space Complexity - O(m * n)
 

### Tabulation : Space Optimized

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,1));
        vector<int> prevRow(n, 1);
        vector<int> currRow(n, 0);
        currRow[0] = 1;

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                currRow[j] = currRow[j-1] + prevRow[j];
            }
            prevRow = currRow;
        }

        return prevRow[n-1];
    }
};

```

> Time Complexity - O(m * n)
> 
> Space Complexity - O(n)

### Combinatronics

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int s = (m-1) + (n-1);
        int r = (m-1);

        double ans = 1;

        for(int i=1;i<=r;i++)
        {
            ans = ans * (s-r+i)/i;
        }
        return (int)ans;
    }
};
```

> Time Complexity - O(min(m,n))
> 
> Space Complexity - O(1)