# Connected Components

Given a undirected Graph consisting of V vertices numbered from 0 to V-1 and E edges. The ith edge is represented by `[ai,bi]`, denoting a edge between vertex ai and bi. We say two vertices u and v belong to a same component if there is a path from `u` to `v` or `v` to `u`. Find the number of connected components in the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.


## DFS Approach

A connected component is a maximal group of vertices such that there is a path between any two vertices in that group.

To find these components:
- Start DFS from any unvisited node.
- It will visit all nodes in its component.
- Repeat DFS for all unvisited nodes and count how many times you started DFS. That’s the number of connected components.

```cpp
class Solution {
  public:

    void dfs(vector<vector<int>> &adjList, vector<bool> &visited, int currNode)
    {
      visited[currNode]=true;

      for(auto nextNode: adjList[currNode])
      {
        if(!visited[nextNode])
          dfs(adjList, visited, nextNode);
      }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
      vector<vector<int>> adjList(V);
      for(int i=0;i<edges.size();i++)
      {
        int ai = edges[i][0];
        int bi = edges[i][1];

        adjList[ai].push_back(bi);
        adjList[bi].push_back(ai);
      }

      vector<bool> visited(V, false);
      int components = 0;
      for(int i=0;i<V;i++)
      {
        if(!visited[i])
        {
          dfs(adjList, visited, i);
          components++;
        }
      }
      return components;
    
    }
};
```

> Time Complexity: `O(V+E)`
> - Building Adjacency List: O(E)
> - DFS Traversal:
>   - Each node is visited once → O(V)
>   - Each edge is traversed once in undirected graph → O(E)
>
> Space Complexity: `O(V+E)`
> - Adjacency List: O(V + E)
> - Visited Array: O(V)
> - Call Stack (DFS): O(V) in worst case (if graph is a long chain)