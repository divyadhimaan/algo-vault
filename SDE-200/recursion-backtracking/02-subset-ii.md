# Subset II

Given an integer array nums, which can have duplicate entries, provide the power set.

## Intuition

- We need to generate all subsets (the power set) of an array that can contain duplicates, but ensure no duplicate subsets appear in the result.
- So we want to explore all possible combinations of elements, while skipping any repeated subset structures caused by duplicate numbers.

```cpp
class Solution {
public:

    void subsetsWithDupUtil(vector<int>&nums, vector<vector<int>> &subsets, vector<int> &tempSubset, int idx){

        subsets.push_back(tempSubset);

        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i-1]==nums[i] )
                continue;
            tempSubset.push_back(nums[i]);
            subsetsWithDupUtil(nums, subsets, tempSubset, i+1);
            tempSubset.pop_back();
        }
    }


    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<int> subset;

        subsetsWithDupUtil(nums, subsets, subset, 0);

        return subsets;
    }
};
```

> Time Complexity: `O(2^n)` due to the recursive exploration of all possible subsets.
> 
> Space Complexity: O(n) primarily due to the depth of the recursion stack, where n is the number of elements in nums. Additional space is used to store the subsets which can be up to O(n * 2^n) in the worst case.