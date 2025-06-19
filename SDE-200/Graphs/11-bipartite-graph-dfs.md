# Bipartite Graph - DFS


A graph is said to be bipartite if it can be colored using two colors such that no two adjacent nodes have same color.

Graph should be undirected.

Practice [Link](https://leetcode.com/problems/number-of-islands/description/)

## Sample 1

![Alt text](/images/graph-k.png)

> output: BIPARTITE
> 
> ![Alt text](/images/graph-l.png)

## Sample 2

![Alt text](/images/graph-m.png)
> output: NOT BIPARTITE
> 
> ![Alt text](/images/graph-n.png)

## Observations

- Any linear graph with no cycle - ```always bipartite```
- With Cycle
  1. Even Cycle Length - Bipartite
  2. odd cycle length - can ```NEVER``` be bipartite


## Note

Carefully handle the disconnected components.




## Approach

Instead of queue call DFS method recursively and also keep last used color.

Two cases possible:
1. ```color[adj_node] == -1```, not yet visited, give opposite color to current node and add to queue
2. ```color[adj_node] == color[current_node]```, not bipartite

## Implementation
```
class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>>& graph, vector<int> &colors, int node, int color)
    {
        colors[node] = color;

        for(int next: graph[node])
        {
            if(colors[next] == -1 && !checkBipartiteDFS(graph, colors, next, 1-color))
                return false;
            else if(colors[next]==color)
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V  = graph.size();
        vector<int> colors(V, -1);

        for(int i=0;i<V;i++)
        {
            if(colors[i] == -1 && !checkBipartiteDFS(graph, colors, i, 0))
                return false;
        }
        return true;
    }
};
```

## Complexities
Time Complexity: O(N*(V+E)) -> to cover all disconnected components