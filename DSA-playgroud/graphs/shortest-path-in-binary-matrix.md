# Shortest Path in Binary Matrix

Practice [Link](https://leetcode.com/problems/shortest-path-in-binary-matrix/description/)


Given an `n x n `binary matrix `grid`, return the `length of the shortest clear path in the matrix`. If there is no clear path, return `-1`.

A clear path in a binary matrix is a path from the top-left cell (i.e., `(0, 0)`) to the bottom-right cell (i.e., `(n - 1, n - 1)`) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.


### Implementation

```cpp
class Solution {
public:
    vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
    vector<int> dy = {0, 0, 1, -1, 1, -1, -1, 1};

    bool isValidCell(int x, int y, int n)
    {
        if(x<0 || x>=n || y<0 || y>=n)
            return false;
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0]==1)
            return -1;

        vector<vector<int>> dist(n, vector<int> (n, 0));
        queue<pair<int,int>> q;

        q.push({0,0});
        dist[0][0] = 1;
        grid[0][0] = 1;

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();


            if(x==n-1 && y==n-1)
                return dist[x][y];

            for(int dir=0;dir<8;dir++)
            {
                int nx = x+dx[dir];
                int ny = y+dy[dir];

                if(isValidCell(nx,ny,n) && grid[nx][ny]==0)
                {
                    dist[nx][ny] = dist[x][y] +1;
                    grid[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
        return -1;
    }
};
```

Time Complexity: O(V^2)



> DFS Appraoch will give TLE as it generates all possible paths, it is time consuming.