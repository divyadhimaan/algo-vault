# Search in 2D matrix
Given a 2-D array mat where the elements of each row are sorted in non-decreasing order, and the first element of a row is greater than the last element of the previous row (if it exists), and an integer target, determine if the target exists in the given mat or not.

## Brute Force
Use 2 loops to find the target.

> Time Complexity: O(n^2)
>
> Space Complexity: O(1)

## Better Approach
For every row, use binary search to find the target, since the matrix is row wise sorted.
```cpp
class Solution{
public:
    bool binarySearch(vector<int> &nums, int target){
        int low=0,high=nums.size()-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]==target)
                return true;

            if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>> &mat, int target){
        int n = mat.size();

        for(vector<int> nums: mat)
        {
            if(binarySearch(nums, target))
                return true;
        }
        return false;
    }
};
```
> Time Complexity: O(n * log n)
> 
> Space Complexity: O(1)
