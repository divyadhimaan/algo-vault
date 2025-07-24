# Find Minimum in Rotated Sorted Array

Pratice [here](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/)

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in `O(log n)` time.

## Brute Force

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;

        for(int i=0;i<nums.size();i++){
            mini = min(mini, nums[i]);
        }
        return mini;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)

## Better Approach: Binary Search

Use binary search to find the minimum in O(log n) time by identifying the sorted halves of the array and narrowing the search space.


- In a rotated sorted array, at least one half is always sorted.
- The minimum element always lies in the unsorted half or at the boundary of the sorted part.

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int s = 0, e = n-1;
        int mini = INT_MAX;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(nums[s] <= nums[mid]) //left half sorted
            {
                mini = min(nums[s], mini);
                s = mid+1;
            }else{
                mini = min(nums[mid], mini);
                e = mid-1;
            }
        }
        return mini;
    }
};
```




> Time Complexity: O(log n)
>
> Space Complexity: O(1)



# Summary 


| **Approach**      | **Description**                                                        | **Time Complexity** | **Space Complexity** | **Code Insight**                                                          |
| ----------------- | ---------------------------------------------------------------------- | ------------------- | -------------------- | ------------------------------------------------------------------------- |
| **Brute Force**   | Traverse the entire array and track the minimum                        | O(n)                | O(1)                 | Simple linear scan using a loop                                           |
| **Binary Search** | Use binary search to find pivot/min by checking sorted/unsorted halves | O(log n)            | O(1)                 | If left half is sorted, discard it; else, move to left and update minimum |
