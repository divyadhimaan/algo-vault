# Maximum Consecutive Ones

Given a binary array nums, return the maximum number of consecutive 1s in the array.

A binary array is an array that contains only 0s and 1s.

## Optimal Solution

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;

        int curr =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 1){
                maxi = max(maxi, curr);
                curr=0;
            }else{
                curr++;
            }
        }
        if(curr)
            maxi = max(maxi, curr);

        return maxi;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)