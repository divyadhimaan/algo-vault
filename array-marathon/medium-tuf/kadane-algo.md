# Max Subarray Sum

Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

A subarray is a contiguous non-empty sequence of elements within an array.

## Brute Force

- Check all subarrays

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;

        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j=i;j<nums.size();j++){
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
```

> Time Complexity: O(n^2) --> TLE
>
> Space Complexity: O(1)
