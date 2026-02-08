# Second Largest
Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.

Array can have duplicates.

## Brute Force
- Sort the array
- Traverse from second last element, when element != last element (coz of duplicates) return element

> Time Complexity: O(nlogn)
>
> Space Complexity: O(1)

## Better Approach

- Traversal 1: Find largest element
- Traversal 2: Find element that is just smaller than largest (element < largest)

> Time Complexity: O(n) + O(n)
>
> Space Complexity: O(1)

## Optimal Approach
```cpp
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {

        int largest = INT_MIN, sec_largest = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>largest){
                sec_largest = largest;
                largest = nums[i];
            }
            else if(nums[i] < largest && nums[i]>sec_largest){
                sec_largest = nums[i];
            }
        }
        return sec_largest == INT_MIN ? -1 : sec_largest;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)