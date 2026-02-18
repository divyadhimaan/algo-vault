# Next Permutation

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integers.
More formally, if all the permutations of the array are sorted in lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted order.

If such arrangement is not possible (i.e., the array is the last permutation), then rearrange it to the lowest possible order (i.e., sorted in ascending order).

## Brute Force

### Intuition
- Find the Pivot (First decreasing point from right)
  - We scan from right to left to find where order breaks
  - We look for: `nums[i] < nums[i+1]`
  - Why? Because everything to the right of that point is already in descending order — meaning it is the largest possible arrangement of that suffix.
- If no pivot found → already largest permutation
  - So next permutation = smallest permutation: sort the array
- Find the next greater element than pivot
  - we want the smallest number greater than pivot on the right side.
  - swap the found number with the pivot.
- Fix the right side (make it smallest possible)
  - To get the next permutation, we need the smallest suffix.
  - sort the right side.

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


```cpp
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        
        int pivot = -1;

        //find pivot
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1])
            {
                pivot = i;
                break;
            }
        }

        //if no pivot found - last permutation
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // find swap for pivot
        for(int i=nums.size()-1;i>=pivot;i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        //sort the array to the right of pivot
        reverse(nums.begin() + pivot+1, nums.end());
    }
};
```


> Time Complexity: `O(n)`
>  - O(n) to find pivot 
>  - O(n) to find swap 
>  - O(n log n) sort (can be O(n) if reverse used)
>
> Space Complexity: O(1)
