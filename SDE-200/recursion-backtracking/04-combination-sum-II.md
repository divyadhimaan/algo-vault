# Combination Sum II

Practice [Here](https://leetcode.com/problems/combination-sum-ii/description/)

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

Note: The solution set must not contain duplicate combinations.

 
```cpp
class Solution {
public:
void combinationSumUtil(vector<int>& nums,vector<int>& temp, vector<vector<int>> &res, int target, int idx, bool preTaken)
    {
        if(idx==nums.size())
        {
            if(target==0){
                res.push_back(temp);
            }
            return;
        }

        combinationSumUtil(nums, temp, res, target, idx+1, false);

        if(idx>0 && nums[idx-1]==nums[idx] && !preTaken)
            return;

        if(nums[idx] <= target){
            temp.push_back(nums[idx]);
            combinationSumUtil(nums, temp, res, target-nums[idx], idx+1, true);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> uniqueCombinations;
        vector<int> temp;
        bool preTaken = false;
        combinationSumUtil(candidates, temp, uniqueCombinations, target, 0,preTaken );

        return uniqueCombinations;
    }
};
```

> Time Complexity: O(2<sup>n</sup>), T -> target
>
> Space Complexity: O(n)