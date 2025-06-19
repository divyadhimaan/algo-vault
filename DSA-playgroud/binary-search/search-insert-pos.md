# Search Insert Position

Practice [Link](https://leetcode.com/problems/search-insert-position/)

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.


## Implementation

We have to return equal or greater than target

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        int res = -1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid]==target)
            {
                res = mid;
                break;
            }else if(nums[mid]<target)
                s = mid+1;
            else
                e = mid-1;
        }
        return res == -1 ? s : res;
    }
};
```


> Time Complexity: O(logn)
>
> Space Complexity: O(1)