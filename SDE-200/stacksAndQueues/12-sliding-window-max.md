# Sliding Window Maximum

Practice [Link](https://leetcode.com/problems/sliding-window-maximum/description/)


You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.


## Naive Approach

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        for(int i=0;i<=n-k;i++)
        {
            int maxi = INT_MIN;
            for(int j=i;j<=i+k-1;j++)
            {
                maxi = max(maxi, nums[j]);
            }
            result.push_back(maxi);
        }
        return result;
    }
};
```

> Time Complexity: `O(n-k)(k)` --> TLE
>
> Space Complexity: `O(n-k)`

## Better Approach

- We need to push new element and pop old element from window at same time ->  queue
- Keep maximum for every window -> monotonic stack (Stores descreasing elements)

> Better to use a deque instead of using two data structures


```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty() && dq.front() == i-k)
                dq.pop_front();

            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
```

> Time Complexity: `O(n)`
>
> Space Complexity: `O(n-k)`
