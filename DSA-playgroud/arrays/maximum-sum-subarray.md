# Maximum Subarray

Practice [here](https://leetcode.com/problems/maximum-subarray/description/)

Given an integer array `nums`, find the subarray with the largest sum, and return its sum.


## Brute Force
- Find all possible subarray sums -> Pick maximum.
  
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            int sum = 0;
            for(int j=i;j<nums.size();j++)
            {
                sum += nums[j];
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }
};
```

> Time Complexity: O(n<sup>2</sup>) --> TLE
>
> Space Complexity: O(1)

## Better Approach: Kadane's Algo

> Kadane’s Algorithm is an efficient method to find the maximum sum of a contiguous subarray in a given array.

- The idea is to keep adding elements to a running sum.
- If at any point the sum becomes negative, discard it by resetting to 0.
- Keep updating the maximum sum seen so far.

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum=0;

        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            maxSum = max(sum, maxSum);
            if(sum<0)
                sum=0;
        }
        return maxSum;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)

# Summary
| **Approach**           | **Description**                                           | **Time Complexity** | **Space Complexity** | **Code Insight**                                                             |
| ---------------------- | --------------------------------------------------------- | ------------------- | -------------------- | ---------------------------------------------------------------------------- |
| **Brute Force**        | Check all possible subarrays and compute their sum        | O(n²)               | O(1)                 | Two nested loops; inefficient for large input                                |
| **Kadane's Algorithm** | Maintain a running sum; reset to 0 if it becomes negative | O(n)                | O(1)                 | Most optimal approach; uses max-so-far and discards negative subarray prefix |
