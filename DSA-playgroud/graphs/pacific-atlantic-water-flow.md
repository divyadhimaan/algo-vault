# Pacific Atlantic Water Flow

Practice [Here](https://leetcode.com/problems/pacific-atlantic-water-flow/description/)


There is an `m x n` rectangular island that borders both the **Pacific Ocean** and **Atlantic Ocean**. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an `m x n` integer matrix `heights` where `heights[r][c]` represents the height above sea level of the cell at coordinate `(r, c)`.

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates `result` where `result[i] = [ri, ci] `denotes that rain water can flow from cell `(ri, ci)` to both the Pacific and Atlantic oceans.



## To Note
To determine if water from each cell can flow to both the Pacific and Atlantic Oceans using DFS or BFS. 

But this approach (checking each cell to reach till ocean) will be inefficient and hard to maintain.

Instead of:
  `"From each cell, can water reach both oceans?"`

Think:
`"From the ocean, how far can water go up (reverse the flow direction)?"`


> Why Reverse Logic?
> 
> - Because it's hard to check from each cell whether it can reach the ocean.
Instead, simulate where the ocean can reach.


1. Use DFS or BFS to start from:
   - Pacific: top row and left column
   - Atlantic: bottom row and right column
2. From these ocean-bordering cells, explore all reachable cells (i.e., reverse water flow: neighbor height >= current height)
3. Intersect both result matrices to find cells that can reach both oceans

## DFS Approach

```cpp
class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};


    bool isValidCell(int x, int y, int m, int n)
    {
        if(x<0 || x>= m || y<0 || y>=n)
            return false;
        return true;
    }


    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>> &reachDest)
    {
        reachDest[r][c] = true;


        for(int dir =0;dir<4;dir++)
        {
            int nr = r + dx[dir];
            int nc = c + dy[dir];

            if(!isValidCell(nr, nc, heights.size(), heights[0].size()))
                continue;

            if(reachDest[nr][nc])
                continue;

            if(heights[nr][nc] >= heights[r][c])
                dfs(heights, nr, nc, reachDest);
        }

        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();


        vector<vector<bool>> reachPacific(m, vector<bool>(n, false));
        vector<vector<bool>> reachAtlantic(m, vector<bool>(n, false));
        
        // left and right column
        for(int i=0;i<m;i++){
            dfs(heights, i, 0, reachPacific);

            dfs(heights, i, n-1, reachAtlantic);
        }

        //top and bottom row
        for(int i=0;i<n;i++){
            dfs(heights, 0, i, reachPacific);

            dfs(heights, m-1, i, reachAtlantic);
        }

        vector<vector<int>> flowableCells;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(reachPacific[i][j] && reachAtlantic[i][j])
                    flowableCells.push_back({i,j});
            }
        }
        return flowableCells;
    }
};
```


> Time Complexity: ```O(m x n)```, 
>  - From each ocean (Pacific and Atlantic), you do a DFS from the border cells.
> - Each cell is visited at most once for each ocean → 2 * (m * n) → O(m * n)
> 
> Space Complexity: ```O(m x n)```
> - Visited matrices: reachPacific, reachAtlantic → each of size m x n
> - Call stack in worst-case DFS depth: O(m * n) in the worst case (completely connected increasing slope)

---
## BFS Approach

```cpp
class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();


        vector<vector<bool>> reachPacific(m, vector<bool>(n, false));
        vector<vector<bool>> reachAtlantic(m, vector<bool>(n, false));


        queue<pair<int,int>> pacificQueue;
        queue<pair<int,int>> atlanticQueue;

        for(int i=0;i<m;i++)
        {
            reachPacific[i][0]=true;
            reachAtlantic[i][n-1]=true;

            pacificQueue.push({i,0});
            atlanticQueue.push({i, n-1});
        }
        

        for(int j=0;j<n;j++){
            reachPacific[0][j]=true;
            reachAtlantic[m-1][j]=true;

            pacificQueue.push({0,j});
            atlanticQueue.push({m-1,j});
        }

        auto bfs = [&](queue<pair<int,int>> &q, vector<vector<bool>> &ocean){
            while(!q.empty())
            {
                auto [r,c] = q.front();
                q.pop();

                ocean[r][c] = true;

                for(int dir=0;dir<4;dir++)
                {
                    int nr = r + dx[dir];
                    int nc = c + dy[dir];

                    if(nr<0 || nr>= ocean.size() || nc<0 || nc>=ocean[0].size())
                        continue;

                    if(!ocean[nr][nc] && heights[nr][nc] >= heights[r][c]){
                        q.push({nr,nc});
                    }
                }
            }
        };

        bfs(pacificQueue, reachPacific);
        bfs(atlanticQueue, reachAtlantic);

        
        vector<vector<int>> flowableCells;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(reachPacific[i][j] && reachAtlantic[i][j])
                    flowableCells.push_back({i,j});
            }
        }
        return flowableCells;
    }
};
```

> Time Complexity: ```O(m x n)```, 
> - BFS starts from all border cells and explores each cell once.
> - Every cell is pushed into queue at most once per ocean → 2 * (m * n) → O(m * n)
> 
> Space Complexity: ```O(m x n)```
> - Queue can hold at most m*n elements in the worst case.
> - Visited matrices: reachPacific, reachAtlantic → each of size m x n
---

# DFS vs BFS

| Feature                         | DFS                                     | BFS              |
| ------------------------------- | --------------------------------------- | ---------------- |
| Uses recursion                  | ✅                                       | ❌                |
| Risk of stack overflow          | ❌                                       | ✅                |
| Easier to write                 | ✅                                       | ❌ (more verbose) |
| Avoids reprocessing naturally   | ❌ (needs check)                         | ✅                |
| Better for deep trees           | ✅                                       | ❌                |
| Better for wide graphs/matrices | ❌                                       | ✅                |
| Performance on this problem     | Good                                    | Often better     |
| Recommended here?               | ✅ (works well if you add visited check) | ✅ (more robust)  |
