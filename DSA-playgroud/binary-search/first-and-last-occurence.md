# Find First and Last Position of Element in Sorted Array

Practice [Link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/)


Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.


## Intiution 

The runtime complexity directly says that binary Search needs to be used.

- Follow normal binary Search algorithm
- To find the first/leftmost occurence of the `target`
  - if target found, store it, but explore more in the left (shift subarray to left),
  - move `end = mid-1`
- To find the last/rightmost occurence of the `target`
  - if target found, store it, but explore more in the right (shift subarray to right)
  - move `start = mid+1`

## Implementation

```cpp
class Solution {
public:
    int BinarySearch(vector<int> &nums, int s, int e, int target, bool searchLeft)
    {
        int res = -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                res = mid;
                if(searchLeft)
                    e = mid-1;
                else
                    s = mid+1;
            }else if(nums[mid]<target)
                s= mid+1;
            else
                e = mid-1;
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int l = BinarySearch(nums, 0, n-1, target, true);
        int r = BinarySearch(nums, 0, n-1, target, false);

        return {l,r};

    }
};
```

> Time Complexity: O(logn)
>
> Space Complexity: O(1)