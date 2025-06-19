# Minimum Spanning Tree: Prim's Algorithm

> `Spanning Tree`: Subset of edges of graph that forms a tree(acyclic), where every node is a part of tree. 
> 
> 1. (Edges = Vertices-1)
> 2. Shouldn't be disconnected
> 3. Acyclic
> 4. Multiple STs possible

> `Minimum Spanning Tree (MST)`: Spanning Tree that has minimum weight among all possible spanning Trees.


Aim is to craete a `weighted`, `connected` and `undirected` graph.



# Prim's Algorithm
`Greedy Algorithm` 
- Suitable for Dense Graph
- Use Priority Queue -> minHeap


## Intiution

Pick smallest weight edge that doesn't cause a cycle.

Use priority_queue to pick the smallest weight edge.

## Algorithm

- Start with empty tree
- Maintain set of all vertices not yet picked.
- Pick the smallest weight edge (minHeap)
- For every vertex u, check all adjacent and pick smallest weight edge.
- Continue, until all vertices picked.
- Use visited array

## Implementation

```cpp

int spanningTree(int V, vector<vector<int>> adj[]) {
        
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(V, false);
    
    // wt -> v;
    pq.push({0,0});
    
    int mstWeight = 0;
    while(!pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if(visited[u])
            continue;
            
        mstWeight += wt;
        visited[u] = true;
        
        for(auto it: adj[u])
        {
            int v = it[0];
            int w = it[1];
            if(!visited[v])
                pq.push({w,v});
        }
        
    }
    return mstWeight;
    
}

```

> Time Complexity: `O(VlogE)` , Sort: O(ElogE), pick and check cycle: E x log(V)
>
> Space Complexity: `O(V^2)` 