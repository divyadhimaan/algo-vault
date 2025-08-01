# Product of Array Except Self

Practice [Here](https://leetcode.com/problems/product-of-array-except-self/description/)

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of nums except `nums[i]`.

The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.


## Brute Force Approach

- For every element (i)
  - Find product of all the elements before it
  - Find product of all elements after it
  - Club the product

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        for(int i=0;i<nums.size();i++)
        {
            int p = 1;
            for(int j=0;j<i;j++)
                p *= nums[j];
            for(int j=i+1;j<nums.size();j++)
                p *= nums[j];

            result.push_back(p);
        }
        return result;
    }
};
```

> Time Complexity: O(n<sup>2</sup>) --> TLE
>
> Space Complexity: O(1)


## Better Approach: prefix Sum

- Find prefix and suffix product for all elements beforehand

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        vector<int> pre(n,1), suff(n,1);
        for(int i=1;i<n;i++)
            pre[i] = pre[i-1] * nums[i-1];

        for(int i=n-2;i>=0;i--)
            suff[i] = suff[i+1] * nums[i+1];


        for(int i=0;i<n;i++)
            result[i] = pre[i] * suff[i];

        return result;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)

## Optimal Approach: Prefix Sum - Space Optimization


```cpp

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        for(int i=1;i<n;i++)
            result[i] = result[i-1] * nums[i-1];

        int suffix = 1;
        for(int i=n-2;i>=0;i--){
            suffix *= nums[i+1];
            result[i] *= suffix;
        }
            
        return result;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)

# Summary


| **Approach**                  | **Description**                                                                    | **Time Complexity** | **Space Complexity**    | **Code Insight**                                                                                 |
| ----------------------------- | ---------------------------------------------------------------------------------- | ------------------- | ----------------------- | ------------------------------------------------------------------------------------------------ |
| **Brute Force**               | For each index, multiply all elements except current                               | O(n²)               | O(1)                    | Two nested loops → TLE on large inputs                                                           |
| **Better (Prefix & Suffix)**  | Precompute prefix & suffix products and multiply them for each index               | O(n)                | O(n)                    | Uses two extra arrays: `pre[i] = product of nums[0..i-1]`, `suff[i] = product of nums[i+1..n-1]` |
| **Optimal (Space Optimized)** | Use output array to store prefix product, and suffix product via one backward pass | O(n)                | O(1) (excluding output) | First pass → prefix in `result`; second pass → multiply with suffix using a variable             |
