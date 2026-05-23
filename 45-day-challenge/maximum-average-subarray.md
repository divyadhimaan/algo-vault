# Maximum Average Subarray I

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

## Sliding Window - Fixed

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        for(int i=0;i<k;i++)
            sum += nums[i];

        int maxSum = sum;

        for(int i=k; i<n;i++){
            sum += nums[i];
            sum -= nums[i-k];

            maxSum = max(sum, maxSum);
        }
        return (double)maxSum/k;
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(1)