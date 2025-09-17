# Top K Frequent Elements

Practice [Link](https://leetcode.com/problems/top-k-frequent-elements/description/)

Given an integer array nums and an integer `k`, return the `k` most frequent elements. You may return the answer in any order.

## Intiution

We need to find the top K frequent elements in the array.

A brute-force approach would count frequencies and sort, but that takes O(m log m) time, where m-> unique elements.

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int num : nums)
            mp[num]++;

        // store into vector
        vector<pair<int,int>> freqList;
        for (auto &x : mp)
            freqList.push_back({x.first, x.second});

        // sort by frequency (descending)
        sort(freqList.begin(), freqList.end(), 
             [](pair<int,int> &a, pair<int,int> &b) {
                 return a.second > b.second;
             });

        // pick top k
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(freqList[i].first);

        return ans;
    }
};

```

- Instead, we:
  - Count frequencies using a hash map.
  - Use a heap (priority queue) to track the top K elements by frequency.

## Implementation using map-heap

```cpp
typedef pair<int,int> pii;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pii> pq;

        unordered_map<int,int> mp;

        // O(n)
        for(int num: nums)
            mp[num]++;

        //O(nlogn)
        for(auto x: mp)
            pq.push({x.second, x.first});

        //O(k)
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
```

> Time Complexity: O(n log n)
>
> Space Complexity: O(n)

## Implementation using Min-heap
```cpp
typedef pair<int,int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for(auto x: mp)
        {
            pq.push({x.second, x.first});
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
```

> Time Complexity: O(n log k)
>
> Space Complexity: O(n)

## Summmary

> Approach 1 (Max Heap) is simpler but less efficient for large n.
> 
> Approach 2 (Min Heap) is more optimized, especially when k << n, since it avoids unnecessary heap storage.