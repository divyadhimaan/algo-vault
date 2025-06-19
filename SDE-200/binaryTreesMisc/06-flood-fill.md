# Flood Fill

Practice [Link](https://leetcode.com/problems/flood-fill/description/)

### Implementation - BFS

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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        if(image[sr][sc] == color)
            return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});

        int initColor = image[sr][sc];

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            image[row][col] = color;

            for(int dir=0;dir<4;dir++)
            {
                int newRow = row + dx[dir];
                int newCol = col + dy[dir];

                if(isValidCell(image, newRow, newCol) && image[newRow][newCol]==initColor)
                    q.push({newRow, newCol});
            }
        }
        return image;
    }
};
```



### Implementation - DFS

```cpp
class Solution {
public:
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,1,0,-1};

    void DFS(vector<vector<int>>& image, int x, int y, int newColor, int originalColor)
    {
        if(image[x][y] == newColor)
            return;

        image[x][y] = newColor;

        for(int k=0;k<4;k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0 && nx<image.size() && ny>=0 && ny<image[0].size() && image[nx][ny] == originalColor)
            {
                DFS(image,nx,ny, newColor, originalColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if(image[sr][sc] == color)
            return image;
        DFS(image,sr,sc, color, image[sr][sc]);
        return image;
    }
};
```


Time Complexity: O(mxn)


Space Complexity: O(mxn)