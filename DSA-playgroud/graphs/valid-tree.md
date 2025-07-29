# Valid Tree

Given `n` nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

## Intiution 

A graph is a valid tree if
- It is connected
- It has no cycles

```cpp
bool validTree(int n, vector<vector<int>>& edges) {
    if(edges.size() != n-1)
        return false;

    vector<vector<int>> adj(n);
    for(auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);

    int count = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        if(visited[node])
            continue;

        visited[node] = true;

        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
                q.push(neighbor);
        }
    }
    return count==n;
}
```