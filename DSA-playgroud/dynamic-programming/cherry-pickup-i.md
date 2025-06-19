# Cherry Pickup - I

Practice [Link](https://leetcode.com/problems/cherry-pickup/description/)


You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.


## Intituion

Instead of going to bottom and then returning to the beginning, we can assume two people starting together and picking cherries.

## DP Approach

```cpp
class Solution {
public:

    int maxCherries(vector<vector<int>>&grid, int i1, int j1, int i2, int j2, int n, int dp[50][50][50][50])
    {
        int cherries = 0;
        if(i1>=n || j1>= n || i2>=n || j2>=n || grid[i1][j1] == -1 || grid[i2][j2]==-1)
            return -10000; 

        if(dp[i1][j1][i2][j2]!= -1)
            return dp[i1][j1][i2][j2];

        if(i1==n-1 && j1==n-1)
            return grid[i1][j1];

        if(i2==n-1 && j2==n-1)
            return grid[i2][j2];

        if(i1==i2 || j1==j2)
            cherries += grid[i1][j1];
        else
            cherries += grid[i1][j1] + grid[i2][j2];


        
        int rr = maxCherries(grid, i1,j1+1, i2, j2+1, n, dp);
        int rd = maxCherries(grid, i1,j1+1, i2+1, j2, n, dp);
        int dd = maxCherries(grid, i1+1,j1, i2+1, j2, n, dp);
        int dr = maxCherries(grid, i1+1,j1, i2, j2+1, n, dp);
        cherries += max({rr,rd,dd,dr});


        dp[i1][j1][i2][j2] = cherries;
        return cherries;
    }


    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int dp[50][50][50][50];
        memset(dp,-1, sizeof(dp));
        return max(0, maxCherries(grid, 0,0, 0, 0, n, dp));

    }
};
```

> Time Complexity: O(n^4)
> Space Complexity: O(n^4)