# Combination Sum

Practice [here](https://leetcode.com/problems/combination-sum/description/)

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

## Brute Force - Recursion

```cpp
class Solution {
public:
    void combinationSumUtil(vector<int>& nums,vector<int>& temp, vector<vector<int>> &res, int target, int i)
    {
        if(i==nums.size())
        {
            if(target==0)
                res.push_back(temp);
            return;
        }

        if(nums[i] <= target){
            temp.push_back(nums[i]);
            combinationSumUtil(nums, temp, res, target-nums[i], i);
            temp.pop_back();
        }
        combinationSumUtil(nums, temp, res, target, i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> uniqueCombinations;
        vector<int> temp;
        combinationSumUtil(candidates, temp, uniqueCombinations, target, 0);
        return uniqueCombinations;
    }
};
```

> Time Complexity: O(2<sup>T</sup>), T -> target
>
> Space Complexity: O(T)



## When to Use Tabulation
- If the problem is about counting the number of ways rather than listing them.
- If the interviewer specifically asks for iterative DP.