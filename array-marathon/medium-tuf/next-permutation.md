# Next Permutation



## Brute Force

```cpp
class Solution {
   public:

   void findAllPermutations(int ind, vector<int> &nums, vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=ind;i<nums.size();i++){
            swap(nums[ind], nums[i]);

            findAllPermutations(ind+1, nums, ans);

            swap(nums[ind], nums[i]);
        }
   }

    vector<vector<int>> getAllPermutations(vector<int>& nums){
        vector<vector<int>> ans;

        findAllPermutations(0, nums, ans);

        sort(ans.begin(), ans.end());
        return ans;
    }

    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> allPermutations = getAllPermutations(nums);

        int idx = 0;
        for(;idx<allPermutations.size();idx++){
            if(allPermutations[idx] == nums){
                break;
            }
        }

        if(idx == allPermutations.size()-1)
            nums = allPermutations[0];
        else 
            nums = allPermutations[idx+1];
    }
};
```

> Time Complexity: O(n!) + O(n!logn!) + O(n!) 
>
> Space Complexity: O(n!)


## Optimal Approach