# Path with Minimum Effort

You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size` rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the `maximum absolute difference in heights` between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Practice [Link](https://leetcode.com/problems/path-with-minimum-effort/)



### Implementation

```cpp
typedef pair<int,pair<int,int>> ppi;
class Solution {
public:
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {1,-1,0,0};
    bool isValidCell(int x, int y, int m, int n)
    {
        if(x<0 || x>= m || y<0 || y>= n)
            return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        vector<vector<int>> eff(m, vector<int> (n, 1e6+5));
        eff[0][0]= 0;
        pq.push({eff[0][0], {0, 0}});

        while(!pq.empty())
        {
            int effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x==m-1 && y==n-1)
                return effort;

            for(int dir=0;dir<4;dir++)
            {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                

                if(isValidCell(nx, ny, m, n))
                {
                    int newEffort = max(effort,abs(heights[nx][ny] - heights[x][y]));
                    if(newEffort < eff[nx][ny])
                    {
                        eff[nx][ny] = newEffort;
                        pq.push({eff[nx][ny], {nx, ny}});
                    }   
                }
            }
        }
        return -1;

    }
};
```

Time Complexity: O(ElogV)
