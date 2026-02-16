# Maximum Subarray Sum

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

## Optimal Solution

- Using kadane's algo
- Traverse array once
  - If during traversal the sum becomes negative, start with sum=0 again. (as negatives wont result to max sum)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxSum=LLONG_MIN;

        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum > maxSum){
                maxSum = sum;
            }
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


## Follow up

- Print the subarray with max sum


```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxSum=LLONG_MIN;

        long long sum = 0;

        int start = 0, ansStart=-1, ansEnd=-1;
        for(int i=0;i<nums.size();i++){

            if(sum==0)
                start=i;

            sum += nums[i];

            if(sum > maxSum){
                maxSum = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum<0){
                sum=0;
            }
        }

        for (int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i] << " ";
        }

        return maxSum;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)