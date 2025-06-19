# Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


Practice [Link](https://leetcode.com/problems/partition-equal-subset-sum/description/)


## Intiution
- Find the total sum of array
- If the total sum cannot be divided into two, 2 subsets with equal sum cannot exist.
- Find the totalSum/2 and use Subset sum equal to target approach.
- If halved sum can be found -> two subsets with equal sum exists. 

## Tabulation Solution

```cpp
class Solution {
public:

    int findTotalSum(vector<int>& nums)
    {
        int sum =0;
        for(int num: nums)
            sum += num;
        return sum;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = findTotalSum(nums);
        if(totalSum%2!=0)
            return false;

        int n = nums.size();
        int subsetSum = totalSum/2;
        vector<vector<bool>> dp(n, vector<bool> (subsetSum+1, false));

        for(int i=0;i<n;i++)
            dp[i][0]= true;

        if(nums[0] <= subsetSum)
            dp[0][nums[0]] = true;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=subsetSum;j++)
            {
                bool not_take = dp[i-1][j];
                bool take = false;

                if(nums[i]<= j)
                    take = dp[i-1][j-nums[i]];
                dp[i][j] = take || not_take;
            }
        }

        return dp[n-1][subsetSum];
    }
};
```

> Time Complexity - `O(n*k)`
> 
> Space Complexity - `O(n*k )`


## Space Optimized

```cpp
class Solution {
public:

    int findTotalSum(vector<int>& nums)
    {
        int sum =0;
        for(int num: nums)
            sum += num;
        return sum;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = findTotalSum(nums);
        if(totalSum%2!=0)
            return false;

        int n = nums.size();
        int subsetSum = totalSum/2;
        vector<bool> prev(subsetSum+1, false);
        vector<bool> curr(subsetSum+1, false);

        prev[0] = true;
        if(nums[0] <= subsetSum)
            prev[nums[0]] = true;

        for(int i=1;i<n;i++)
        {
            curr[0] = true;
            for(int j=1;j<=subsetSum;j++)
            {
                bool not_take = prev[j];
                bool take = false;

                if(nums[i]<= j)
                    take = prev[j-nums[i]];
                curr[j] = take || not_take;
            }
            prev = curr;
        }

        return curr[subsetSum];
    }
};
```


> Time Complexity - `O(n*k)`
> 
> Space Complexity - `O(k)`