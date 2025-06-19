# Kth Largest in unsorted Array




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

## Better Approach - Use Min Heap

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