# Left Rotate Array by One

Given an integer array nums, rotate the array to the left by one.

> Input: nums = [1, 2, 3, 4, 5]
> 
> Output: [2, 3, 4, 5, 1]


```cpp
class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int n = nums.size();
        int firstEle = nums[0];

        for(int i=1;i<n;i++){
            nums[i-1] = nums[i];
        }
        nums[n-1] = firstEle;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)