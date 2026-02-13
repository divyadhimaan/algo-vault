# Move Zeros to End

Given an integer array nums, move all the 0's to the end of the array. The relative order of the other elements must remain the same.

This must be done in place, without making a copy of the array.


## Brute Force
TC - O(2*N) (one for copying and other for copying back to original)
Sc - O(N)

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }

        int nz = temp.size();

        for (int i = 0; i < n; i++) {
            if(i<nz)
                nums[i] = temp[i];
            else
                nums[i] = 0;
        }

    }
};
```

> Time Complexity: O(2*n)
>
> Space Complexity: O(1)


## Optimal Approach: Two pointer

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)