# Subarray Sum Equals K

Practice [Link](https://leetcode.com/problems/subarray-sum-equals-k/description/)

Given an array of integers `nums` and an integer `k`, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.


## Brute Force
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int resultCnt =0;
        
        for(int i=0;i<nums.size();i++)
        {
            int sum = 0;
            for(int j=i;j<nums.size();j++)
            {
                sum += nums[j];
                if(sum==k)
                    resultCnt++;
            }
        }
        return resultCnt;
    }
};
```

> Time Complexity: O(n^2)
>
> Space Complexity: O(1)

## Prefix Sum

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n);

        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];
        
        int count = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(prefixSum[i]==k)
                count++;

            int val = prefixSum[i]-k;
            if(mp.find(val) != mp.end())
                count += mp[val];
            
            mp[prefixSum[i]]++;
        }
        return count;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)