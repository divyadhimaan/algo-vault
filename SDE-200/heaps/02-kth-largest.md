# Kth Largest Element in an Array

Practice [Link](https://leetcode.com/problems/kth-largest-element-in-an-array/)

Given an integer array `nums` and an integer `k`, return the `kth` largest element in the array.

Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.


## Naive Approach

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};

```
> Time Complexity: O(nlogn)
>
> Space Complexity: O(1)


## Better Approach

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;

        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }

        for(int i=k;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()> k)
                pq.pop();
        }
        return pq.top();
    }
};
```

> Time Complexity: O(nlogk)
>
> Space Complexity: O(1)