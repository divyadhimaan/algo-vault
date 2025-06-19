# Minimum Spanning Tree: Kruskal's Algorithm

> `Spanning Tree`: Subset of edges of graph that forms a tree(acyclic), where every node is a part of tree. 
> 
> 1. (Edges = Vertices-1)
> 2. Shouldn't be disconnected
> 3. Acyclic
> 4. Multiple STs possible

> `Minimum Spanning Tree (MST)`: Spanning Tree that has minimum weight among all possible spanning Trees.


Aim is to craete a `weighted`, `connected` and `undirected` graph.



# Kruskal's Algorithm
`Greedy Algorithm` 
- Suitable for Sparse Graph
- Use DSU


## Intiution

Pick smallest weight edge that doesn't cause a cycle.

 - For cycle detection between vertex `u` and `v`, use Union-Find. => Atmost O(logV)


## Algorithm

- Sort all edges in increasing order of weight. 
- Pick smallest edge
  - Check if it forms a cycle
  - No cycle: include egde
  - cycle: doscard edge
- Repeat step 2, until V-1 edges are found. 

## Implementation

```cpp

class DSU {
  vector<int> parent;
  vector<int> rank;
  
  public: 
  DSU(int n)
  {
      parent.resize(n);
      rank.resize(n,0);
      for(int i=0;i<n;i++)
        parent[i]= i;
  }
  
  int find(int x)
  {
      if(x == parent[x])
        return x;
        
        return parent[x] = find(parent[x]);
  }
  
  void Union(int x, int y)
  {
      int x_rep = find(x);
      int y_rep = find(y);
      
      if(x_rep == y_rep)
        return;
        
        if(rank[x_rep] > rank[y_rep])
        {
            parent[y_rep] = x_rep;
        }else if(rank[x_rep] < rank[y_rep]){
            parent[x_rep] = y_rep;
        }else{
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
  }
};

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};
class Solution {
  public:
  
    static bool cmp(const Edge &a, const Edge &b)
    {
        return a.weight < b.weight;
    }
    
    void preprocessAdjList(int V, vector<vector<int>> adj[], vector<Edge> &edges)
    {
        for(int i=0;i<V;i++)
        {
            for(auto neighbour: adj[i])
            {
                if(i<neighbour[0])
                    edges.push_back(Edge(i, neighbour[0], neighbour[1]));
            }
        }
    }
  
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<Edge> edges;
        
        preprocessAdjList(V, adj, edges);
        
        sort(edges.begin(), edges.end(), cmp);
        
        DSU d(V);

        int mstWeight=0;
        for(auto edge: edges)
        {
            int u = edge.u;
            int v = edge.v;
            int wt = edge.weight;
            if(d.find(u) != d.find(v))
            {
                mstWeight += wt;
                d.Union(u,v);
            }
        }
        return mstWeight;
    }
    
};

```

> Time Complexity: `O(ElogE + VlogE) ~ O(ElogV)` , Sort: O(ElogE), pick and check cycle: E x log(V)
>
> Space Complexity: `O(V+E)` 