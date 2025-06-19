# Shortest Path: Floyd Warshall Algorithm

`MULTI SOURCE ALGORITHM`


The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix. `mat[i][j]` denotes the weight of the edge from `i` to `j`. If `mat[i][j] = -1`, it means there is `no edge` from `i` to `j`.
Note: Modify the distances for every pair in place.

Practice [Link](https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1)

> Doesn't work for negative edge cycle

## Intiution

For every pair of vertices `i` and `j`, there will be `k` vertex as intermediate in the path.

![Alt text](/images/graph-p.png)

## Alogrithm

> Pre-requisites
> 1. if there is no edge between `i` and `j` , `mat[i][j] = INF`
> 2. if `i==j`, `mat[i][j] = 0`


For every pair of vertices `i` and `j`, consider an intermediate vertex k, such that:

`mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j])`

We will maintain a matrix.


## Implementation

```cpp

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        int V = mat.size();
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(mat[i][j]==-1)
                    mat[i][j] = 1e9;
                if(i==j)
                    mat[i][j]=0;
            }
            
        }
        
        for(int k=0;k<V;k++)
        {
            for(int i=0;i<V;i++)
            {
                for(int j=0;j<V;j++)
                {
                        mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(mat[i][j]==1e9)
                    mat[i][j] = -1;
            }
            
        }
        
    }
};
```

> Time Complexity: `O(V^3 )` 
>
> Space Complexity: `O(V^2 )` 