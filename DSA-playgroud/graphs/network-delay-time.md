# Network Delay Time


You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges `times[i] = (ui, vi, wi)`, where `ui` is the source node, `vi` is the target node, and `wi` is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return the minimum time it takes for all the `n` nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return `-1`.



```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            int s = times[i][0];
            int e = times[i][1];
            int d = times[i][2];

            adj[s].push_back({e,d});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        dist[k]=0;

        while(!pq.empty())
        {
            int delay = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto nextNode: adj[node])
            {
                int dst = nextNode.first;
                int del = nextNode.second;

                if(delay + del < dist[dst])
                {
                    dist[dst] = delay + del;
                    pq.push({dist[dst], dst});
                }
            }
        }


        int max =  *max_element(dist.begin()+1, dist.end());
        return max==INT_MAX ? -1 : max;

    }
};
```


> Time Complexity: O((V + E) log V)
>
> Space Complexity: O(V+E)