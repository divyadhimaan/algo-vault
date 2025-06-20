# Top K Frequent Elements

Practice [Here](https://leetcode.com/problems/top-k-frequent-elements/description/)


## Brute Force - Hashing + Sorting
```cpp
class Solution {
public:
    bool static cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.first > b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;

        for(int num: nums)
            hash[num]++;

        vector<pair<int,int>> temp;
        for(auto it: hash)
            temp.push_back({it.second, it.first});

        sort(temp.begin(), temp.end(), cmp);

        vector<int> result;
        for(int i=0;i<k;i++)
            result.push_back(temp[i].second);

        return result;
    }
};
```

> Time Complexity: `O(n + mlogm)`, n = number of strings in strs, m = number of unique elements
> 
> Space Complexity: `O(n)`, 

## Priority Queue Based

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;

        for(int num: nums)
            hash[num]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it: hash)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)
                pq.pop();
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
```

> Time Complexity: `O(n + mlogk)`, n = number of strings in strs, m = number of unique elements
> 
> Space Complexity: `O(n )`, 