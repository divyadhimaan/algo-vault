# Topological sort - BFS

Practice [Link](https://www.geeksforgeeks.org/problems/topological-sort/1)

Topological Sort is a linear ordering of nodes such that if edge `u -> v` exists, then `u` appears before `v`.

In-degree of a node: Number of incoming edges for a node


![Alt text](/images/graph-h.png)
> In-degree of node 0: 0
>
> In-degree of node 1: 1
> 
> In-degree of node 2: 3
> 
> In-degree of node 3: 1

## Sample

![Alt text](/images/graph-f.png)
> [0,1,4,2,3]


## Note
Graph can also be disconnected -> Check for every node as source/starting node.


This can be possible only for `DAG ( Directed acyclic graph)` because in an undirected graph we can’t decide which node will come first because there will be no direction, and if there is a cycle topological order will not be possible (See below figure to understand why it is not possible for graphs containing cycle). For reference, see below image.



![exception-case](/images/graph-g.png)

## Intiution

Start from node that doesn't have any previous edges (inDegree == 0).


## Implementation

```

vector<int> topologicalSort(vector<vector<int>>& adj) {
    vector<int> inDegree(adj.size(), 0);
    
    // Maintain an in-degree array -> O(E)
    for(int i=0;i<adj.size();i++)
        for(int j=0;j<adj[i].size();j++)
            inDegree[adj[i][j]]++;

    queue<int> q;
    for(int i=0;i<inDegree.size();i++)
        if(inDegree[i]==0)
            q.push(i);
            
    vector<int> topoSort;
            
    while(!q.empty())
    {
        int currNode = q.front();
        q.pop();
        
        topoSort.push_back(currNode);
        for(int adjNode: adj[currNode])
        {
            inDegree[adjNode]--;
            if(inDegree[adjNode]==0)
                q.push(adjNode);
        }
    }
    return topoSort;
}

```


## Complexities

### Time Complexity: O(V+E) + O(N)
We are exploring every vertex V and exploring all its edges. 
O(N) -> For covering disconnected components

Same TC as BFS



### Space Complexity: O(N)+O(V+E), 
O(N) to keep visited nodes, and O(V+E) to create the adjacency list.