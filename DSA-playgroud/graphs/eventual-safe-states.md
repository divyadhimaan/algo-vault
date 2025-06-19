# Find Eventual Safe States

There is a directed graph of n nodes with each node labeled from `0` to `n - 1`. The graph is represented by a 0-indexed 2D integer array graph where `graph[i]` is an integer array of nodes adjacent to node `i`, meaning there is an edge from node `i` to each node in `graph[i]`.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Practice [Link](https://leetcode.com/problems/find-eventual-safe-states/description/)

## Sample


> Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
> 
![Alt text](/images/graph-f.png)
>
>  Output: [2,4,5,6]
>


### Approach

- Detect cycles in the graph:
  - Use a DFS to track whether a node is part of a cycle. Keep a visit array to mark visited nodes and an inStack array to detect back edges (indicating a cycle).
- Mark safe nodes:
  - After the DFS traversal, any node not in a cycle (inStack[node] is false) is a safe node.
- Sort and return the safe nodes:
  - Safe nodes are collected, sorted (if needed), and returned.


### Implementation - DFS

```cpp
class Solution {
public:
    bool checkCycle(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &inStack, int node)
    {
        visited[node] = true;
        inStack[node] = true;

        for(auto next: graph[node])
        {
            if(!visited[next] && checkCycle(graph, visited, inStack, next))
            {
                return true;
            }else if(inStack[next])
                return true;    
        }
        inStack[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V), inStack(V);

        vector<int> safeNodes;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                checkCycle(graph, visited, inStack, i);
        }
        for(int i=0;i<V;i++)
            if(!inStack[i])
                safeNodes.push_back(i);
        return safeNodes;
    }
};
```

- Time complexity: 𝑂(𝑉+𝐸)
where 𝑉 is the number of nodes and 𝐸 is the number of edges.

- Space complexity: O(V)