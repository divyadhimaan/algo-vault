# Find the city with the smallest number of neighbors in a threshold distance

Practice [Link](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)

There are n cities numbered from `0` to `n-1.` Given the array edges where `edges[i] = [fromi, toi, weighti]` represents a bidirectional and weighted edge between cities `fromi` and `toi`, and given the integer `distanceThreshold`.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most `distanceThreshold`, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

## Dijkstra's Algo
Run Dijkstra's algorithm from each city to find the shortest paths from that city to all others.
For each run, count how many cities are reachable within the threshold.

```cpp
typedef pair<int,int> pii; 
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pii>> adjList(n);

        for(auto edge: edges)
        {
            int source = edge[0];
            int dest = edge[1];
            int wt = edge[2];

            adjList[source].push_back({dest, wt});
            adjList[dest].push_back({source, wt});
        }

        int minReachable=n, result=0;

        for(int i=0;i<n;i++)
        {
            vector<int> dist(n, INT_MAX);
            dist[i]=0;

            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push({0, i});

            while(!pq.empty())
            {
                auto [wt,node] = pq.top();
                pq.pop();

                for(auto [nextNode, currWt]: adjList[node])
                {
                    if(wt + currWt <= distanceThreshold && dist[nextNode] > wt + currWt)
                    {
                        dist[nextNode] = wt+ currWt;
                        pq.push({dist[nextNode], nextNode});
                    }
                }
            }
            int reachable = 0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[j]<=distanceThreshold)
                    reachable++;
            }
            if(minReachable >= reachable){
                minReachable = reachable;
                result = i;
            }
        }
        return result;
        
    }
};
```

> Time Complexity: O(n * (E log V)) if using priority queue (Dijkstra n times)
>
> Space Complexity: O(n^2)


## Floyd warshall's approach
Precompute shortest distances between all pairs of cities using dynamic programming.
Then, for each city, count how many other cities are reachable within the given distance threshold.

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; ++i)
            dist[i][i] = 0;

        for(auto edge: edges)
        {
            int s = edge[0];
            int d = edge[1];
            int w = edge[2];

            dist[s][d] = w;
            dist[d][s] = w;
        }

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        int minReachable = n, result=-1;
        for(int i=0;i<n;i++)
        {
            int reachable =0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && dist[i][j] <= distanceThreshold)
                    reachable++;
            }

            if(reachable <= minReachable){
                minReachable = reachable;
                result = i;
            }
        }
        return result;
    }
};
```


> Time Complexity: O(n^3)
>
> Space Complexity: O(n^2)


| Feature                   | Dijkstra (Per Node)                                             | Floyd-Warshall                                       |
| ------------------------- | --------------------------------------------------------------- | ---------------------------------------------------- |
| **Time Complexity**       | `O(n * (E log V))` if using priority queue (Dijkstra `n` times) | `O(n^3)`                                             |
| **Space Complexity**      | `O(n^2)` for adjacency list and distance arrays                 | `O(n^2)` for distance matrix                         |
| **Best For**              | Sparse graphs, when `n` is large but `edges` are few            | Dense graphs or when `n` is small (e.g., `n <= 100`) |
| **All-Pairs Info**        | No, runs Dijkstra from each node                                | Yes, gives shortest path between every pair          |
| **Implementation**        | More complex due to heap & visited logic                        | Very simple nested loops                             |
| **Accuracy & Tie-break**  | Accurate if distances are tracked right                         | Fully accurate for all-pairs shortest paths          |
| **Edge Case Sensitivity** | Needs care with visited/distance update                         | Handles cycles and multiple paths cleanly            |
