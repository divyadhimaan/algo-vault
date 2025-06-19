# Top K Frequent Elements

Practice [Link](https://leetcode.com/problems/top-k-frequent-elements/description/)

Given an integer array nums and an integer `k`, return the `k` most frequent elements. You may return the answer in any order.

## Intiution

We need to find the top K frequent elements in the array.

A brute-force approach would count frequencies and sort, but that takes O(n log n) time.

- Instead, we:
  - Count frequencies using a hash map.
  - Use a min-heap (priority queue) of size k to track the top K elements by frequency.
  - At the end, the heap contains the K most frequent elements.


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

 