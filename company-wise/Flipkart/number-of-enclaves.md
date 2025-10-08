# Number of enclaves

Given an N x M binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking 
off the boundary of the grid. Find the number of land cells in the grid for which we cannot walk off the boundary 
of the grid in any number of moves.

## Intuition

- The problem requires finding land cells in a binary matrix that are completely surrounded by other land cells and cannot connect to the boundary of the grid by moving up, down, left, or right. 
- The initial thought is that any land cell directly connected to the boundary or indirectly connected via other land cells should not be counted as an enclave. 
- Therefore, a clever way to solve this involves identifying and marking all land cells that are reachable from the boundary. 
- The remaining unmarked land cells will be the enclaves.

## Implementation

```cpp
class Solution{
public:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};

    bool isValid(int row, int col, int totalRow, int totalCol){
        return row>=0 && row<totalRow && col>=0 && col<totalCol;
    }

    void bfs(vector<vector<int>> &grid, queue<pair<int,int>> &q, vector<vector<bool>> &visited){
        int m = grid.size();
        int n = grid[0].size();

        while(!q.empty())
        {
            auto [row, col]= q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nRow = row + dx[i];
                int nCol = col + dy[i];

                if(isValid(nRow, nCol, m, n) && 
                    grid[nRow][nCol]==1 &&
                    visited[nRow][nCol]==false
                    ){
                        visited[nRow][nCol]=true;
                        q.push({nRow, nCol});
                    }
            }
        }
    }

    int numberOfEnclaves(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1){
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
        }

        bfs(grid,q,visited);

        int totalEnclaves =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    totalEnclaves++;
                }
            }
        }

        return totalEnclaves;
    }
};
```

## Complexity Analysis
> - Time Complexity: `O(m*n)` due to the initialisation of visited array, the queue population, and the final counting loop, combined with the BFS which visits each node at most once.
> 
> - Space Complexity: `O(m*n)` due to the visited array and the queue, which in the worst case, can contain all the land cells.