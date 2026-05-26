# Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

## Brute Force

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int last=-1;
        bool has_found = false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == target && has_found == false)
            {
                has_found = true;
                ans.push_back(i);
                last = i;
            }
            else if(nums[i] == target)
            {
                last = i;
            }
        }
        if(last != -1)
            ans.push_back(last);
        else
        {
            ans.push_back(-1);
            ans.push_back(-1);

        }
        
        return ans;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)

## Binary Search

- Tweak the BS approach to find the left most occurrence and right most occurrence.

```cpp
class Solution {
public:
    int BS(vector<int>& nums, int low, int high, int target){
        int res = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                res = mid;
                high = mid-1;
            }else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }

    int BS1(vector<int>& nums, int low, int high, int target){
        int res = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                res = mid;
                low = mid+1;
            }else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int l = BS(nums, 0, n-1, target);
        int r = BS1(nums, 0, n-1, target);

        return {l,r};
    }
};
```

> Time Complexity: O(log n)
> 
> Space Complexity: O(1)


## Binary Search: Single Method

```cpp
class Solution {
public:
    int BS(vector<int>& nums, int low, int high, int target, bool findLeft){
        int res = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                res = mid;
                if(findLeft)
                    high = mid-1;
                else
                    low = mid+1;
            }else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int l = BS(nums, 0, n-1, target, true);
        int r = BS(nums, 0, n-1, target, false);

        return {l,r};
    }
};
```
> Time Complexity: O(log n)
>
> Space Complexity: O(1)