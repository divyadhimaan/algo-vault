# Strongly Connected Components - Kosaraju's algorithm

> A component is called a Strongly Connected Component(SCC) only if for every possible pair of vertices `(u, v)` inside that component, `u` is reachable from `v` and `v` is reachable from `u`.

Note: Strongly connected components(SCC) are only valid for directed graphs.

Practice [Link](https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

## The Algorithm

- **Sort all the nodes according to their finishing time**:
To sort all the nodes according to their finishing time, we will start DFS from node 0 and while backtracking in the DFS call we will store the nodes in a stack data structure. The nodes in the last SCC will finish first and will be stored in the last of the stack. After the DFS gets completed for all the nodes, the stack will be storing all the nodes in the sorted order of their finishing time.
- **Reverse all the edges of the entire graph:**
Now, we will create another adjacency list and store the information of the graph in a reversed manner.
- **Perform the DFS and count the no. of different DFS calls to get the no. of SCC:**
Now, we will start DFS from the node which is on the top of the stack and continue until the stack becomes empty. For each individual DFS call, we will increment the counter variable by 1. We will get the number of SCCs by just counting the number of individual DFS calls as in each individual DFS call, all the nodes of a particular SCC get visited.
- Finally, we will get the number of SCCs in the counter variable. If we want to store the SCCs as well, we need to store the nodes in some array during each individual DFS call in step 3.


## Note: 

- The first step is to know, from which node we should start the DFS call.
- The second step is to make adjacent SCCs unreachable and to limit the DFS traversal in such a way, that in each DFS call, all the nodes of a particular SCC get visited.
- The third step is to get the numbers of the SCCs. In this step, we can also store the nodes of each SCC if we want to do so.
  
> Note: The sorting of the nodes according to their finishing time is very important. By performing this step, we will get to know where we should start our DFS calls. The top-most element of the stack will finish last and it will surely belong to the SCC1. So, the sorting step is important for the algorithm.

## Implementation

```cpp
class Solution {
  public:
    void DFS1(vector<vector<int>> &adj, vector<int> &visited, stack<int> &stk, int node)
    {
        visited[node] = true;
        for(int next: adj[node])
            if(!visited[next])
                DFS1(adj, visited, stk, next);
                
        stk.push(node);
    }
    
    void DFS2(vector<vector<int>> &adj, vector<int> &visited, int node)
    {
        visited[node] = true;
        for(int next: adj[node])
        {
            if(!visited[next])
                DFS2(adj, visited, next);
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> visited(V);
        stack<int> stk;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                DFS1(adj, visited, stk, i);
        }
        
        
        vector<vector<int>> adjT(V);
        for(int i=0;i<V;i++)
        {
            visited[i]=0;
            for(auto v: adj[i])
                adjT[v].push_back(i);
        }
        
        int scc=0;
        while(!stk.empty())
        {
            int curr = stk.top();
            stk.pop();
            
            if(!visited[curr]){
                scc++;
                DFS2(adjT, visited, curr);
            }
        }
        return scc;
        
    }
};


```

> Time Complexity: `O(V+E) + O(V+E) + O(V+E)` ~ `O(V+E)` , where V = no. of vertices, E = no. of edges. The first step is a simple DFS, so the first term is O(V+E). The second step of reversing the graph and the third step, containing DFS again, will take O(V+E) each.
>
> Space Complexity:` O(V)+O(V)+O(V+E)`, where V = no. of vertices, E = no. of edges. Two O(V) for the visited array and the stack we have used. O(V+E) space for the reversed adjacent list.