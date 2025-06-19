# Rotten Oranges

You are given an `m x n` grid where each cell can have one of three values:

`0` representing an empty cell,
`1` representing a fresh orange, or
`2` representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Practice [Link](https://leetcode.com/problems/rotting-oranges/description/)

### Sample
> Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
> 
![Alt text](/images/graph-e.png)

> Output: 4

### Implementation

```cpp
class Solution {
public:
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};

    bool isValidCell(vector<vector<int>>& grid, int x, int y)
    {
        if(x<0 || x>=grid.size() || y<0 || y>= grid[0].size())
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int freshOranges = 0;
        queue<pair<int,int>> rottenOranges;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    rottenOranges.push({i,j});
                else if(grid[i][j]==1)
                    freshOranges++;
            }
        }
        if(freshOranges==0)
            return 0;

        

        int time = -1;
        while(!rottenOranges.empty())
        {
            int size = rottenOranges.size();
            for(int i=0;i<size;i++)
            {
                int row = rottenOranges.front().first;
                int col = rottenOranges.front().second;
                rottenOranges.pop();

                for(int dir=0;dir<4;dir++)
                {
                    int newRow = row + dx[dir];
                    int newCol = col + dy[dir];
                    

                    if(isValidCell(grid, newRow, newCol) && grid[newRow][newCol]==1)
                    {
                        grid[newRow][newCol] = 2;
                        rottenOranges.push({newRow, newCol});
                        freshOranges--;
                    }
                }
            }
            time++;
        }
        if(freshOranges > 0)
            return -1;
        if(time==-1)
            return 0;
        return time;

    }
};
```

Time Complexity: O(V^2)