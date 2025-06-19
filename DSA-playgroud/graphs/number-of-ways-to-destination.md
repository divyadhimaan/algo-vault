# Number of Ways to Arrive at Destination

You are in a city that consists of `n` intersections numbered from `0` to `n - 1` with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer `n` and a 2D integer array roads where `roads[i] = [ui, vi, timei]` means that there is a road between intersections `ui` and `vi` that takes `timei` minutes to travel. You want to know in how many ways you can travel from intersection `0` to intersection `n - 1` in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo `109 + 7`.

```cpp
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adjList(n);

        for(int i=0;i<roads.size();i++)
        {
            int src = roads[i][0];
            int dst = roads[i][1];
            int time = roads[i][2];

            adjList[src].push_back({dst, time});
            adjList[dst].push_back({src, time});
        }

        vector<long long> times(n,LLONG_MAX);
        vector<int> ways(n,0);
        times[0] = 0;
        ways[0] = 1;

        // time, node
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});

        while(!pq.empty())
        {
            auto it = pq.top();
            long long currTime = it.first;
            int node = it.second;
            pq.pop();


            for(auto it: adjList[node])
            {
                int next = it.first;
                long long time = it.second;

                if(currTime + time < times[next])
                {
                    times[next] = currTime + time;
                    ways[next] = ways[node];
                    pq.push({times[next], next});
                }else if(currTime + time == times[next])
                    ways[next] = (ways[next] + ways[node]) % MOD;
            }
        }
        return ways[n-1];
    }
};
```


> Time Complexity: O(m log n), m -> number of edges, n -> number of nodes
>
> Space Complexity: O(m+n)