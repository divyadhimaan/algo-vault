# M Coloring Problem

Given an integer M and an undirected graph with N vertices and E edges. The goal is to determine whether the graph can be coloured with a maximum of M colors so that no two of its adjacent vertices have the same colour applied to them.

In this context, colouring a graph refers to giving each vertex a different colour. If the colouring of vertices is possible then return true, otherwise return false.


## Backtracking approach
```cpp
class Solution{
public:

    bool isSafe(int col, int node, vector<int> &colors, vector<vector<int>> &adjList){
        for(int nextNode: adjList[node]){
            if(colors[nextNode]==col)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<int>> &adjList, int node, int tColors, int n, vector<int> &colors){
        if(n==node)
            return true;
        for(int i=1;i<=tColors;i++){
            if(isSafe(i, node, colors, adjList)){
                colors[node]=i;
                if(solve(adjList, node+1, tColors, n, colors))
                    return true;
                colors[node]=0;
            }
        }
        return false;
        
    }

    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
    	vector<vector<int>> adjList(n);
        vector<int> assignedColors(n,0);
        for(auto edge: edges){
            int source = edge[0];
            int dest = edge[1];

            adjList[source].push_back(dest);
            adjList[dest].push_back(source);
        }
        assignedColors[0] = 1;

        if(solve(adjList, 0, m, n, assignedColors))
            return true;
        return false;
    }
};
```

> Time Complexity:The time complexity is O(m^n) in the worst case due to the recursive exploration of all possible color assignments.
> 
> Space Complexity:The space complexity is O(n) due to the recursion depth and the 'colors' vector.