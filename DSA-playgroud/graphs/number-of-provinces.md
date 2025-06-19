# Number of Provinces


There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

A `province` is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where `isConnected[i][j] = 1` if the `ith` city and the `jth` city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return the total number of `provinces`.

Practice [Link](https://leetcode.com/problems/number-of-provinces/description/)

## Sample
![Alt text](/images/graph-d.png)
> OUTPUT: 2



## Implementation
```cpp
class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, vector<int> &visited, int source)
    {
        visited[source] = true;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!visited[i] && isConnected[source][i]==1)
                DFS(isConnected, visited, i);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, false);
        int provinces=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                DFS(isConnected, visited, i);
                provinces++;
            }
                
        }
        return provinces;
    }
};

```

## Complexities
Time Complexity - ```O(V^2)```

Space Complexity - Auxilary Space