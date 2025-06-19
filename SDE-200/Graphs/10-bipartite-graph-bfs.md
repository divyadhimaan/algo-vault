# Bipartite Graph - BFS


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

Use colors array to maintain color of nodes(also acts as visited)

Two cases possible:
1. ```color[adj_node] == -1```, not yet visited, give opposite color to current node and add to queue
2. ```color[adj_node] == color[current_node]```, not bipartite

## Implementation
```
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V  = graph.size();
        vector<int> colors(V, -1);
        queue<int> q;

        for(int i=0;i<V;i++)
        {
            if(colors[i]==-1)
            {
                q.push(i);
                colors[i]=0;

                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for(auto next: graph[node])
                    {
                        if(colors[next]==-1)
                        {
                            colors[next]=1-colors[node];
                            q.push(next);
                        }

                        else if(colors[next]==colors[node])
                            return false;
                    }
                }

            }

        }
        return true;
    }
};
```

## Complexities
Time Complexity: O(N*(V+E)) -> to cover all disconnected components