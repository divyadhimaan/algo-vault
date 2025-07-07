# All Paths From Source to Target

Practice [here](https://leetcode.com/problems/all-paths-from-source-to-target/description/)


```cpp
class Solution {
public:

    void findAllPaths(vector<vector<int>>& graph, vector<vector<int>> &allPaths, vector<int> &path, int currNode, int dest)
    {
        if(currNode==dest){
            allPaths.push_back(path);
            return;
        }

        for(int nextNode: graph[currNode])
        {
            path.push_back(nextNode);
            findAllPaths(graph, allPaths, path, nextNode, dest);
            path.pop_back();
        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        vector<int> path;
        int n = graph.size();

        path.push_back(0);
        findAllPaths(graph, allPaths, path, 0, n-1);

        return allPaths;
    }
};
```

> Time Complexity: `O(2^N * N)`
> - 2^N possible paths in worst-case (each node has 2 children).
> - Each path takes O(N) to build (copied into result).
> Total: O(2^N * N)
>

> Space Complexity: `O(N)` (excluding output)
> - Call stack + path vector can be O(N).
> - Output space (not counted as auxiliary): O(2^N * N)