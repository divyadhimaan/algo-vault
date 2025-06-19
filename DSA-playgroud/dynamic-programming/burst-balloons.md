# Burst Balloons

Practice [Link](https://leetcode.com/problems/burst-balloons/description/)

You are given n balloons, indexed from `0` to `n - 1`. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the `ith` balloon, you will get `nums[i - 1] * nums[i] * nums[i + 1]` coins. If `i - 1` or `i + 1` goes out of bounds of the array, then treat it as if there is a balloon with a `1` painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.


## Intiution

Similar question to rod cutting problem.

We will pick every balloon and try to burst it, and proceeding to the left balloons until we find the maximum coins.


## Recursive Solution
```cpp
class Solution {
public:

    int solveCoins(vector<int> &nums, int i, int j)
    {
        if(i>j)
            return 0;

        int maxCoins = INT_MIN;

        for(int idx = i; idx<=j; idx++)
        {

            int coins = (nums[i-1] * nums[idx] * nums[j+1]) + solveCoins(nums, i, idx-1) + solveCoins(nums, idx+1, j);
            maxCoins = max(maxCoins, coins);
        }
        return maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return solveCoins(nums, 1, n);
    }
};
```


## Memoized Solution

```cpp
class Solution {
public:

    int solveCoins(vector<int> &nums, int i, int j, vector<vector<int>> &memo)
    {
        if(i>j)
            return 0;

        if(memo[i][j] != -1)
            return memo[i][j];

        int maxCoins = INT_MIN;

        for(int idx = i; idx<=j; idx++)
        {

            int coins = (nums[i-1] * nums[idx] * nums[j+1]) + solveCoins(nums, i, idx-1, memo) + solveCoins(nums, idx+1, j, memo);
            maxCoins = max(maxCoins, coins);
        }
        return memo[i][j] = maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> memo(302, vector<int>(302, -1));

        return solveCoins(nums, 1, n, memo);
    }
};
```