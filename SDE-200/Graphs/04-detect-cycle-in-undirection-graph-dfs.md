# Detect Cycle in an undirected graph - DFS

Practice [Link](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

![Graph with no cycle](../images/graph-b.png)
> No Cycle


![graph with cycle](../images/graph-a.png)
> Cycle exists

## Note
Graph can also be disconnected -> Check for every node as source/starting node.

Visited array cannot be the only check here since for DFS the adjacent node can also be the parent node itself, which will always be visited.

## Intiution
- Start from one node(unvisited) and explore all nodes, keep track of rhe parent node.
- Use visited array to keep track of explored nodes.
- For every node, iterate over the adjacent nodes
  - If not visited, call dfs() on the node and return true if its true.
  - If not visited, and the node is not the parent df current node -> cycle exists.
- Return false


## Implementation

```
bool checkCycleDFS(vector<vector<int>>& adj, vector<bool> &visited, int source, int parent)
    {
        
        visited[source]=true;
        
        for(auto dest: adj[source])
        {
            if(!visited[dest])
            {
                if(checkCycleDFS(adj, visited, dest, source))
                    return true;
            }
            else if(dest != parent)
                return true;
        }
        
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        vector<bool> visited(adj.size(), false);
        vector<int> visitedNodes;
        
        for(int i=0;i<adj.size();i++)
        {
            if(!visited[i] && checkCycleDFS(adj, visited, i, -1))
                return true;
        }
        return false;
    }
```


## Complexities

### Time Complexity: O(V+E) + O(N), 
We are exploring every vertex V and exploring all its edges. 
O(N) -> For covering disconnected components



### Space Complexity: O(N)+O(V+E), 
O(N) to keep visited nodes, and O(V+E) to create the adjacency list.