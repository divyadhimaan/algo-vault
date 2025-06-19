# Cheapest Flights Within K Stops

Practice [Link](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)


There are `n` cities connected by some number of flights. You are given an array `flights` where `flights[i] = [fromi, toi, pricei] `indicates that there is a flight from city `fromi` to city `toi` with cost `pricei`.

You are also given three integers `src`, `dst`, and `k`, return the cheapest price from `src` to `dst` with at most `k` stops. If there is no such route, return `-1`.

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<flights.size();i++)
        {
            int src = flights[i][0];
            int des = flights[i][1];
            int price = flights[i][2];

            adj[src].push_back({des, price});
        }


        queue<pair<int,pair<int,int>>> q;

        vector<int> prices(n,INT_MAX);
        q.push({0,{src,0}});
        prices[src]=0;

        while(!q.empty())
        {
            int stops = q.front().first;
            int currCity = q.front().second.first;
            int price = q.front().second.second;
            q.pop();

            if(stops>k)
                continue;

            for(auto it: adj[currCity])
            {
                int neighborCity = it.first;
                int cost = it.second;
                if(price + cost < prices[neighborCity] && stops<=k)
                {
                    prices[neighborCity] = price + cost;
                    q.push({stops+1, {neighborCity, prices[neighborCity]}});
                }
            }
        }
        if(prices[dst]==INT_MAX)
            return -1;
        return prices[dst];
    }
};
```