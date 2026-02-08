# Largest Element

Given an array of integers nums, return the value of the largest element in the array

## Sorting
- Sort the array
- Return the last element

> Time Complexity: O(nlogn)
>
> Space Complexity: O(1)

## Linear Scan

- Scan the array, keeping note of largest element

```cpp
class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largest = INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>largest)
                largest = nums[i];
        }
        return largest;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)