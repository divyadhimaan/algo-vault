# Redundant Connection

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where `edges[i] = [ai, bi]` indicates that there is an edge between nodes `ai` and `bi` in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Practice [Link](https://leetcode.com/problems/redundant-connection/description/?envType=problem-list-v2&envId=union-find)


### Implementation

```cpp
class DSU{
    vector<int> parent;
    vector<int> rank;
public:

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=0;i<=n;i++)
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

        if(x_rep != y_rep)
        {
            if(rank[x_rep] > rank[y_rep])
                parent[y_rep] = x_rep;
            else if(rank[y_rep] > rank[x_rep])
                parent[x_rep] = y_rep;
            else{
                parent[y_rep] = x_rep;
                rank[x_rep]++;
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU d(n);
        vector<int> result;

        for(auto edge: edges)
        {
            vector<int> temp;
            int u = edge[0];
            int v = edge[1];
            if(d.find(u)!=d.find(v))
            {
                d.Union(u,v);
            }else{
                return edge;
            }
        }
        return {};
    }
};
```

Time Complexity: O(V+E)