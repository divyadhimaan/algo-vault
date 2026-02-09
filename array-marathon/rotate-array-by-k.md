# Left Rotate Array by K Places

Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.

> Input: nums = [1, 2, 3, 4, 5, 6], k = 2
>
> Output: nums = [3, 4, 5, 6, 1, 2]


## Brute Force
- K times rotate by One
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
    void rotateArray(vector<int>& nums, int k) {
        for(int i=0;i<k;i++){
            rotateArrayByOne(nums);
        }
    }
};

```

> Time Complexity: O(k*n)
> 
> Space Complexity: O(1)

## Optimal Approach: Segment Reversal

- Reversal Property: Reversing a segment of the array changes the order but keeps the elements intact. By reversing the segments first and then the entire array, you rearrange the elements correctly without needing extra space.

```cpp
class Solution {
public:

    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)

