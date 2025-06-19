# Binary Subarrays With Sum

Practice [Link](https://leetcode.com/problems/binary-subarrays-with-sum/description/)

Given a binary array `nums` and an integer `goal`, return the number of non-empty subarrays with a sum `goal`.

A subarray is a contiguous part of the array.

## Prefixsum + Hashmap

```cpp
class Solution {
public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefixCount;
        prefixCount[0]=1;
        int sum=0,cnt=0;

        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(prefixCount.count(sum-goal))
                cnt += prefixCount[sum-goal];
            prefixCount[sum]++;
        }
        return cnt;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)


## Sliding window Approach

```cpp
class Solution {
public:
    int helper(vector<int> &nums, int goal)
    {
        if(goal<0)
            return 0;
        int l = 0,r=0;

        int currSum = 0, cnt=0;
        while(r < nums.size())
        {
            currSum += nums[r];
            while(currSum > goal && l<=r)
            {
                currSum -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal)-helper(nums, goal-1);
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)