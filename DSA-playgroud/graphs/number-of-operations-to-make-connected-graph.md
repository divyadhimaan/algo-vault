# Number of operations to make network connected

Given a graph with `n` vertices and `m` edges. 
The graph is represented by an array `Edges`, where `Edge[i] = [a, b]` indicates an edge between vertices `a` and `b`. 
One edge can be removed from anywhere and added between any two vertices in one operation. 
Find the minimum number of operations that will be required to make the graph connected. 
If it is not possible to make the graph connected, return `-1`.

## 1. DFS Based

```cpp
class Solution{
public:

    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int currNode){
        visited[currNode] = true;

        for(auto nextNode: adj[currNode]){
            if(!visited[nextNode])
                dfs(adj, visited, nextNode);
        }
    }

    int solve(int n, vector<vector<int>> &Edge){
        vector<vector<int>> adj(n);

        if(Edge.size() < n-1)
            return -1;
        for(auto edge: Edge)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int cc = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cc++;
                dfs(adj, visited, i);
            }   
        }

        return cc-1;
    }
};

```

> Time Complexity:O(n + m), where n is the number of nodes and m is the number of edges.
> 
> Space Complexity:O(n), due to the visited array and recursion stack in the worst-case.


## Disjoint Set Based

```cpp
class UnionFind {
public:

    vector<int> parent, rank;
    int components;

    UnionFind(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        components=n;
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }

    int find(int x)
    {
        if(x==parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void Unite(int x, int y){
        int xRep = find(x);
        int yRep = find(y);

        if(xRep == yRep)
            return;

        if(rank[xRep] > rank[yRep]){
            parent[yRep]= xRep;
        }else if(rank[xRep] < rank[yRep]){
            parent[xRep] = yRep;
        }else{
            parent[yRep]= xRep;
            rank[xRep]++;
        }

        components--;
    }
};

class Solution{
public:
    int solve(int n, vector<vector<int>> &Edge){
        UnionFind uf(n);

        if(Edge.size() < n-1)
            return -1;

        for(auto edge: Edge){
            int u = edge[0];
            int v = edge[1];

            uf.Unite(u,v);
        }
        return uf.components-1;
    }
};

```

> Time Complexity:O(m * alpha(n)), where m is the number of edges and alpha(n) is the inverse Ackermann function, which grows very slowly.
> 
> Space Complexity:O(n) due to the parent and rank vectors in the UnionFind data structure.


## Comparison

| Step               | DFS                                                                                             | Union-Find                                         |
|--------------------|-------------------------------------------------------------------------------------------------|----------------------------------------------------|
| Building structure | `O(n + m)`                                                                                      | `O(n)`                                             |
| Processing edges   | `O(m)`                                                                                          | `O(m * α(n))` *(α(n) ≈ constant)*                  |
| Overall            | **O(n + m)**                                                                                    | **O(m * α(n)) ≈ O(m)**                             |
| Use case           | slightly faster in practice, especially for large dense graphs or repeated connectivity checks. | intuitive and fine for small/medium sparse graphs. |


