# Surrounded Regions


You are given an ```m x n``` matrix board containing letters ```'X'``` and ```'O'```, capture regions that are surrounded:

**Connect**: A cell is connected to adjacent cells horizontally or vertically.

**Region**: To form a region connect every 'O' cell.

**Surround**: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

To capture a surrounded region, replace all ```'O's ```with ```'X's``` in-place within the original board. You do not need to return anything.

Practice [Link](https://leetcode.com/problems/surrounded-regions/description/)

## Sample
![Alt text](/images/graph-c.png)

## Intiution
If we start traversing all the boundary touching groups, in the end the inner '0' will never be touched.

## Approach
* Store all the cells taht touch the boundary and have '0' in a queue.
* Do a BFS traversal on all the stored cells and mark them visited.
* In the end, traverse the grid and find all the cells that have '0' and are not marked visited

## Implementation
```cpp
class Solution {
public:
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0 ,0,-1,1};
    bool isValid(vector<vector<char>>& board, int x, int y, vector<vector<bool>> &visited)
    {
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y] != 'O' || visited[x][y]==true)
            return false;
        return true;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // first column
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
            {
                visited[i][0]=true;
                q.push({i,0});
            }
        }

        //last column
        for(int i=0;i<m;i++)
        {
            if(board[i][n-1]=='O')
            {
                visited[i][n-1]=true;
                q.push({i,n-1});
            }
        }

        // first row
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O')
            {
                visited[0][i]=true;
                q.push({0,i});
            }
        }

        // last row
        for(int i=0;i<n;i++)
        {
            if(board[m-1][i]=='O')
            {
                visited[m-1][i]=true;
                q.push({m-1,i});
            }
        }

        while(!q.empty())
        {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            visited[x][y] = true;

            for(int dir=0;dir<4;dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(isValid(board, nx, ny,visited))
                    q.push({nx,ny});
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' && visited[i][j]==false)
                    board[i][j] = 'X';
            }
        }
    }
};
```

## Complexities
Time Complexity - ```O(V^2)```

Space Complexity - Auxilary Space