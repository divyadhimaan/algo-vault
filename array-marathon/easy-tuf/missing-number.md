# Missing Number

Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.

## Brute Force
- Two loops, to linear search every number from 0 to n

> Time Complexity: O(n^2),
>
> Space Complexity: O(1)

## Better Approach

- Use freq map

> Time Complexity: O(n) + O(n)
>
> Space Complexity: O(n)


## Better Approach - II

- Sort and find
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int missing = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=missing)
                return missing;
            missing++;
        }
        return nums.size();
    }
};
```
> Time Complexity: O(nlogn)
>
> Space Complexity: O(n)

## Optimal Approach: Summation Property

- Find sum of first n numbers: SumN = (n)*(n-1)/2
- Find sum of given array: Sum
- Missing = SumN - sum

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sumN = n * (n+1)/2;

        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        return sumN - sum;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)


## Optimal Approach: XOR

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorR = 0;

        for(int i=0;i<nums.size();i++){
            xorR ^= (i+1);
            xorR ^= nums[i];
        }

        return xorR;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)