# House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Practice [Link](https://leetcode.com/problems/house-robber/description/)

### Recursive

```cpp
class Solution {
public:

    int robHouses(vector<int> &nums, int idx)
    {
        if(idx <0)
            return 0;

        int take = nums[idx] + robHouses(nums, idx-2);
        int notTake = robHouses(nums, idx-1);
        return max(take, notTake);
    }

    int rob(vector<int>& nums) {
        return robHouses(nums, nums.size()-1);
    }
};
```

> Time Complexity: O(2^n) -> TLE
> 
> Space Complexity: O(n)


### Memoized version

```cpp
class Solution {
public:
    int robHouses(vector<int> &nums, int idx, vector<int> &memo)
    {
        if(idx <0)
            return 0;

        if(memo[idx]!=-1)
            return memo[idx];

        int take = nums[idx] + robHouses(nums, idx-2, memo);
        int notTake = robHouses(nums, idx-1, memo);
        return memo[idx] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        return robHouses(nums, n-1, memo);
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(n)



### Tabulation version

```cpp
class Solution {
public:

    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];

        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        for(int idx=2;idx<n;idx++)
        {
            dp[idx] = max(dp[idx-1], nums[idx] + dp[idx-2]);
        }

        return dp[n-1];
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(n)




### Tabulation: Space Optimized

```cpp
class Solution {
public:

    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];

        int n = nums.size();
        int prev2 = nums[0];
        int prev1 = max(nums[1], nums[0]);
        int curr = prev1;

        for(int idx=2;idx<n;idx++)
        {
            curr = max(prev1, nums[idx] + prev2);
            prev2=prev1;
            prev1=curr;
        }

        return curr;
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(1)