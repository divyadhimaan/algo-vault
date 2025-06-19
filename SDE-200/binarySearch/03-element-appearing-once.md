# Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

## Brute Force - XOR

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
            ans ^= nums[i];
        return ans;
    }
};
```

> Time Complexity: O(logn)
>
> Space Complexity: O(1)

## Better - Binary Search

Since every element in the sorted array appears exactly twice except for the single element, we know that if we take any element at an even index (0-indexed), the next element should be the same. 

Similarly, if we take any element at an odd index, the previous element should be the same. 

Therefore, we can use binary search to compare the middle element with its adjacent elements to determine which side of the array the single element is on.

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0, right= nums.size()-1;

        while(left<right)
        {
            int mid = (left+right)/2;

            if(mid%2==1)
                mid--;

            if(nums[mid] != nums[mid+1])
                right = mid;
            else
                left = mid+2;

        }
        return nums[left];
    }
};
```

> Time Complexity: O(logn)
>
> Space Complexity: O(1)