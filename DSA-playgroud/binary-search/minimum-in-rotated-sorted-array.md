# Find Minimum in Rotated Sorted Array


Practice [Link](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)


Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

## Initiution

- We cannot directly eliminate the sorted half without storing the minimum. 
- At any time, if a segment is sorted, the minimum must lie at the beginning of that segment.
- So we check:
  - If the left half is sorted, the minimum might be at `nums[s]`, but the actual minimum may lie in the right half, so we store the current `nums[s]` and search the right half.
  - If the right half is sorted, the pivot (minimum) must lie in the left half, so we store `nums[mid]` and search the left half.

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();


        int s = 0, e =n-1;
        int ans = INT_MAX;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(nums[s] <= nums[mid]) //first half sorted
            {
                ans = min(ans,nums[s]);
                s = mid+1;
            }
            else//seconf half sorted
            {
                ans = min(ans,nums[mid]);
                e = mid-1;
            }
        }
        return ans;
    }
};
```
> Time Complexity: O(logn)
>
> Space Complexity: O(1)