# Detect Cycle in an directed graph - BFS

Practice [Link](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

Given an directed graph with V vertices and E edges, check whether it contains any cycle or not. 

![Graph with no cycle](/images/graph-c.png)
> No Cycle


![graph with cycle](/images/graph-d.png)
> Cycle exists

## Note
Graph can also be disconnected -> Check for every node as source/starting node.

Use DFS algorithm if need to use the nodes in the cycle.


## Intiution

Solving it using BFS - Kahn's Algo for Topological Sort.

- While sorting the graph in topolocal order if it successfully removes all vertices from graph i.e. all the nodes have inDegree as 0, no cycle

- If remaining vertices have inDegree > 0 => atleast one cycle exists.
- Keep a track of visited nodes.



## Implementation

```


bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> inDegree(V,0);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                inDegree[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++)
            if(inDegree[i]==0)
                q.push(i);
        
        int totalNodesVisited=0;
        while(!q.empty())
        {
            int currNode = q.front();
            q.pop();
            totalNodesVisited++;
            
            for(auto adjNode: adj[currNode])
            {
                inDegree[adjNode]--;
                if(inDegree[adjNode]==0)
                {
                    q.push(adjNode);
                }
            }
        }
        return totalNodesVisited != V;
    }

```


## Complexities

### Time Complexity: O(V+E) + O(N)
We are exploring every vertex V and exploring all its edges. 
O(N) -> For covering disconnected components

Same TC as BFS



### Space Complexity: O(N)+O(V+E), 
O(N) to keep visited nodes, and O(V+E) to create the adjacency list.