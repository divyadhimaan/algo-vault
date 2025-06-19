# Shortest Path Algorithm - Dijkstra algorithm
`SINGLE SOURCE ALGORITHM`


Given a weighted, undirected and connected graph where you have given adjacency list adj. You have to find the shortest distance of all the vertices from the source vertex src, and return a list of integers denoting the shortest distance between each node and source vertex src.

Note: The Graph doesn't contain any negative weight edge.

Practice [Link](https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1)

## Note

Cannot have negative edge cycle. -> FAILS

> `Why?`
> 
> The problem with negative weights arises from the fact that Dijkstra’s algorithm assumes that once a node is added to the set of visited nodes, its distance is finalized and will not change. However, in the presence of negative weights, this assumption can lead to incorrect results.

## Algorithm

- We start by initializing an adjacency list which will store all the adjacent nodes for a particular node along with the weights   associated with them.
- Then, as a part of the initial configuration, we define a dist array to store the updated shortest distances for each node, a priority queue for storing the distance-node pairs, and a source node.
- In addition to this, we also declare a ‘parent’ array which would store the parent node for each node and will update itself to a different parent if a shorter path from a node is found at some point in time.
- At the start, all nodes’ parents have been set to the nodes themselves to indicate that the traversal has not yet been started.
- For every node at the top of the queue, we pop the element out and look out for its adjacent nodes. If the current reachable distance is better than the previous distance (dis + edW < dist[adjNode]), indicated by the distance array, we update the distance and push it into the queue.
- A node with a lower distance would be at the top of the priority queue as opposed to a node with a higher distance because we are using a min-heap.
- In addition to the previous step, we will also update the parent array to the node from where the current node came while traversing.
- By following step 5 repeatedly until our queue becomes empty, we would get the minimum distance from the source node to all other nodes and also our parent array would be updated according to the shortest path.
- Now, we run a loop starting from the destination node storing the node’s parent and then moving to the parent again (backtrack) till the parent[node] becomes equal to the node itself.
- At last, we reverse the array in which the path is being stored as the path is in reverse order. Finally, we return the ‘path’ array.

## Data structures Used

- Priority Queue (min-heap): store path-> node
- dist array: to store distance from source
- parent array: to store the path -> can backtrack and find path until `parent[u] != u`

## Implementation

```cpp
typedef pair<int,int> pii;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        vector<int> dist(adj.size(), INT_MAX);
        
        pq.push({0,src});
        dist[src] = 0;
        
        while(!pq.empty())
        {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            

            for(auto it: adj[u])
            {
                int v = it.first;
                int dis = it.second;
                
                if(dist[v] > wt + dis )
                {
                    dist[v] = wt+dis;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
        
    }


```

> Time Complexity: `O( E log(V) )` { for Dijkstra’s Algorithm } + O(V) { for backtracking in order to find the parent for each node } Where E = Number of edges and V = Number of Nodes.
>
> Space Complexity: `O( |E| + |V| )` { for priority queue and dist array } + O( |V| ) { for storing the final path } Where E = Number of edges and V = Number of Nodes.