# Remove duplicates from sorted array

Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that each unique element appears only once.

Return the number of unique elements in the array.

If the number of unique elements be k, then,
- Change the array nums such that the first k elements of nums contain the unique values in the order that they were present originally. 
- The remaining elements, as well as the size of the array does not matter in terms of correctness. 
- The driver code will assess correctness by printing and checking only the first k elements of the modified array.

An array sorted in non-decreasing order is an array where every element to the right of an element is either equal to or greater in value than that element.

## Brute Force
- Use Hashset to store all elements
- Update the array with k elements (non-duplicates)
- Hashset handles sorting automatically


## Optimal Approach: Two Pointer

- Use Two Pointers
- `firstPointer` → points to the last unique element
- `secondPointer` → scans the array to find new values

> Time Complexity: O(n)
>
> Space Complexity: O(n)

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int firstPointer = 0, secondPointer = 1;
        while(secondPointer < nums.size()){
            if(nums[firstPointer] != nums[secondPointer]){
                nums[firstPointer+1] = nums[secondPointer];
                firstPointer++;
            }
            secondPointer++;
        }

        return firstPointer+1;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)