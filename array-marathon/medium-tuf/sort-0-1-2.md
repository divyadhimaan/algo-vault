# Sort an array of 0's 1's and 2's

Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.

The sorting must be done in-place, without making a copy of the original array.

## Brute Force: Sorting

```cpp
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
```

> Time Complexity: O(nlogn)
>
> Space Complexity: O(1)

## Better Approach: Store freq of 0s, 1s and 2s

```cpp
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) cnt0++;
            else if (nums[i] == 1) cnt1++;
            else cnt2++;
        }

        for (int i = 0; i < cnt0; i++) nums[i] = 0;

        for (int i = cnt0; i < cnt0 + cnt1; i++) nums[i] = 1; 
        
        for (int i = cnt0 + cnt1; i < nums.size(); i++) nums[i] = 2;
    }
};
```
> Time Complexity: O(2*n)
>
> Space Complexity: O(1)

## Optimal Approach: Dutch National Flag Algo

- Divide the array into three regions: `[ 0s | 1s | unknown | 2s ]`
- And keep expanding these regions while scanning.

```cpp
class Solution {
public:
    void sortZeroOneTwo(vector<int>& nums) {
        int low = 0, mid = 0, high=nums.size()-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low++], nums[mid++]);
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid], nums[high--]);
            }
        } 
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)
