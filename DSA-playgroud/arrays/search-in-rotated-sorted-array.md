# Search in Rotated Sorted Array

Practice [Here](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)

There is an integer array `nums` sorted in ascending order (with distinct values).

Prior to being passed to your function, `nums` is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array `nums` after the possible rotation and an integer target, return the index of `target` if it is in nums, or -1 if it is not in nums.

You must write an algorithm with `O(log n) `runtime complexity.


## Brute Force: Linear Search

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
                return i;
        }
        return -1;
    }
};
```


> Time Complexity: O(n) 
>
> Space Complexity: O(1)

## Better Approach: Binary Search

- Rotated Array Always Has One Sorted Half
- If the start ≤ mid, then left half is sorted.
  - Now check whether the target lies in the left sorted half
- If the left half isn’t sorted, the right half must be sorted.
  - Similarly, check if target lies in the right sorted half and adjust search bounds accordingly.


```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int start =0, end = n-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;

            if(nums[mid]==target)
                return mid;

            else if(nums[start] <= nums[mid]) //left half sorted
            {
                if(nums[start] <= target && target <= nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }
            else //right half sorted
            {
                if(nums[mid] <= target && target <= nums[end])
                    start = mid+1;
                else
                    end = mid-1;
            }

        }
        return -1;
    }
};
```


> Time Complexity: O(log n) 
>
> Space Complexity: O(1)