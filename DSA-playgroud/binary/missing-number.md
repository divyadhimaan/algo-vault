# Missing Number

Practice [here](https://leetcode.com/problems/missing-number/)

Given an array nums containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.


## Maths Approach

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expSum =( n * (n+1))/2;

        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }
        return expSum -sum;
    }
};
```
> Time Complexity: O(n)
>
> Space Complexity: O(1)


## Bit Manipulation Approach

`Property 1`: OR of two same numbers is always 0 i.e. a ^ a = 0. 
`Property 2`: XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.

Now, let’s XOR all the numbers between 1 to N.

`xor1 = 1^2^.......^N`

Let’s XOR all the numbers in the given array.(contains all the numbers except the missing one).

`xor2 = 1^2^......^N` 

Now, if we again perform XOR between xor1 and xor2, we will get:

`xor1 ^ xor2 = (1^1)^(2^2)^........^(missing Number)^.....^(N^N)`

- Here all the numbers except the missing number will form a pair and each pair will result in 0 according to the XOR property. 
- The result will be

  `0 ^ (missing number) = missing number (according to property 2).`



```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2=0;
        for(int i=0;i<nums.size();i++)
        {
            xor1 = xor1^nums[i];
            xor2 = xor2^(i+1);
        }
        return xor1^xor2;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)