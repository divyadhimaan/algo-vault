# House Robber - II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a `circle`. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Practice [Link](https://leetcode.com/problems/house-robber-ii/description/)
### Recursive

```cpp
class Solution {
public:
    int robHouses(vector<int> &nums, int start, int end)
    {
        if(start>end)
            return 0;

        int take = nums[end] + robHouses(nums, start, end-2);
        int notTake = robHouses(nums, start, end-1);
        return max(take, notTake);
    }

    int rob(vector<int>& nums) {
        return max(robHouses(nums, 1, nums.size()-1), robHouses(nums, 0, nums.size()-2));
    }

};
```

> Time Complexity: O(2^n)
> 
> Space Complexity: O(n)


### Memoized version

```cpp
class Solution {
public:
    int robHouses(vector<int> &nums, int start, int end, vector<int> &memo)
    {
        if(start>end)
            return 0;

        if(memo[end]!=-1)
            return memo[end];

        int take = nums[end] + robHouses(nums, start, end-2, memo);
        int notTake = robHouses(nums,start, end-1, memo);
        return memo[end] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        vector<int> memo1(nums.size(),-1);
        vector<int> memo2(nums.size(),-1);
        return max(robHouses(nums, 1, nums.size()-1, memo1), robHouses(nums, 0, nums.size()-2, memo2));
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
    int robHouses(vector<int>& nums, int start, int end) {
        
        int n = end-start+1;
        if(n==0)
            return 0;
        if(n==1)
            return nums[start];

        vector<int> dp(n, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);

        for(int idx=2;idx<n;idx++)
        {
            dp[idx] = max(dp[idx-1], nums[start+idx] + dp[idx-2]);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        
        int case1 = robHouses(nums, 0, n-2);
        int case2 = robHouses(nums, 1, n-1);

        return max(case1, case2);
    }
};

```

> Time Complexity: O(n)
> 
> Space Complexity: O(n)


## Space Optimized

```cpp
class Solution {
public:
    int robHouses(vector<int>& nums, int start, int end) {
        
        int n = end-start+1;
        if(n==0)
            return 0;
        if(n==1)
            return nums[start];

        
        int prev2 = nums[start];
        int prev1 = max(nums[start], nums[start+1]);
        int curr = prev1;

        for(int idx=2;idx<n;idx++)
        {
            curr = max(prev1, nums[start+idx] + prev2);
            prev2 = prev1;
            prev1=curr;
        }

        return curr;
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        
        int case1 = robHouses(nums, 0, n-2);
        int case2 = robHouses(nums, 1, n-1);

        return max(case1, case2);
    }
};

```

> Time Complexity: O(n)
> 
> Space Complexity: O(1)