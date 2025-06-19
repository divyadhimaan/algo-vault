# DFS TRAVERSAL

Practice [Link](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)

Given a graph G, 
Depth First Search traverses all nodes by going ahead to all the levels, when no more nodes are left in current path, it backtracks.

![Alt text](/images/dfs-traversal.png)

> Output: [1,2,5,6,3,4,8,7]



## Intiution
- Maintain a visited visited arry to avoid visiting twice.
- Traversal terminates when all nodes are completely explored.


## Implementation

```

void dfs(vector<vector<int>>& adj, vector<int> &ans, int source, vector<bool> &visited)
{
    if(visited[source])
        return;
        
    ans.push_back(source);
    visited[source] = true;
        
    for(auto neighbor: adj[source])
    {
        dfs(adj, ans, neighbor, visited);
    }
}

vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    vector<int> ans;
    vector<bool> visited(adj.size(), 0);
    dfs(adj, ans, 0, visited);
    return ans;
}
```


## Complexities

### Time Complexity: O(V+E), 
We are exploring every vertex V and exploring all its edges. 



### Space Complexity: O(N)+O(V+E), 
O(N) to keep visited nodes, and O(V+E) to create the adjacency list.