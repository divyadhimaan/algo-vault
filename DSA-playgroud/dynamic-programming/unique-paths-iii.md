# Unique Paths - III

You are given an m x n integer array grid where grid[i][j] could be:

- `1` representing the starting square. There is exactly one starting square.
- `2` representing the ending square. There is exactly one ending square.
- `0` representing empty squares we can walk over.
- `-1` representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.



Practice [Link](https://leetcode.com/problems/unique-paths-iii/description/)


## Implementation

### A. DFS Approach
```cpp
class Solution {
public:
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,1,-1};
    int result = 0, empty=1;
    bool isValid(vector<vector<int>> &grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == -1)
            return false;
        return true;
    }
    void DFS(vector<vector<int>>& grid, int i, int j, int count)
    {
        if(!isValid(grid,i,j))
            return;

        if(grid[i][j]==2)
        {
            if(empty==count)
                result++;
            return;
        }

        grid[i][j] = -1;
        for(int k=0;k<4;k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            DFS(grid, ni, nj, count+1);
        }
        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int startRow, startCol;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    startRow = i;
                    startCol = j;
                }else if(grid[i][j]==0)
                    empty++;
            }
        }
        DFS(grid, startRow, startCol, 0);
        return result;

    }
};
```
