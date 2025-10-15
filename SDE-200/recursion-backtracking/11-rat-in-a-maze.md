# Rat in a Maze

```cpp
class Solution{
    public:
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    vector<char> dirChar = {'D', 'R', 'U', 'L'};

    bool isValidMove(int i, int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }

    void findPathUtil(vector<vector<int> > &grid, vector<string> &allPaths, string &currPath, int row, int col, int tRows, int tCols){
        if(row == tRows-1 && col == tCols-1){
            allPaths.push_back(currPath);
            return;
        }
        grid[row][col]=2;

        for(int dir=0;dir<4;dir++){
            int nRow = row + dx[dir];
            int nCol = col + dy[dir];

            if(isValidMove(nRow, nCol, tRows, tCols) && grid[nRow][nCol]== 1){
                
                currPath += dirChar[dir];
                findPathUtil(grid, allPaths, currPath, nRow, nCol, tRows, tCols);
                
                currPath.pop_back();
            }
        }
        grid[row][col]=1;
    }

    vector<string> findPath(vector<vector<int> > &grid) {
        
        vector<string> allPaths;
        string currPath="";

        if(grid[0][0]==0)
            return allPaths;

        int tRows = grid.size();
        int tCols = grid[0].size();


        findPathUtil(grid, allPaths, currPath, 0, 0, tRows, tCols);
        return allPaths;
    }
};
```

> Time Complexity: `O(4^(m*n))` where m is the number of rows and n is the number of columns in the grid. Each cell can have up to 4 possible moves, leading to an exponential time complexity in the worst case.
> 
> Space Complexity: `O(m*n)` due to the recursion depth in the worst-case scenario (when the path can visit every cell) and the space used to store the paths. The grid is modified in place.