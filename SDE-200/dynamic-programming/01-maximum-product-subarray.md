# MAXIMUM PRODUCT SUBARRAY

Practice [Link](https://leetcode.com/problems/maximum-product-subarray/description/)

Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.


## Brute Force 

- Generate all subarrays and check the product

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int p = nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                maxi = max(p, maxi);
                p *= nums[j];
            }
            maxi = max(p, maxi);
        }
        
        return maxi;
    }
};
```

> Time Complexity: `O(n^2)`, 
>
> Space Complexity: `O(1)`, 



