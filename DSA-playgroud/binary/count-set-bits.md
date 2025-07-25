# Number of 1 Bits

Practice [Here](https://leetcode.com/problems/number-of-1-bits/description/)

Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

## Shift Right and Count


```cpp
class Solution {
public:
    int hammingWeight(int n) {
        int noSetBits = 0;

        while(n)
        {
            if(n&1)
                noSetBits++;
            n = n>>1;
        }
        return noSetBits;
    }
};
```


> Time Complexity: O(1) (at most 32 iterations for 32-bit integers)
>
> Space Complexity: O(1)

## Brian Kernighan's Algo

Every time we do n = n & (n - 1), we remove the lowest set bit.

This runs in number of set bits, not 32.

#### Why (n & (n - 1)) works:
- Subtracting 1 from n flips all bits after the rightmost 1 (including it)
- n & (n - 1) removes the rightmost 1
  

```cpp
class Solution {
public:
    int hammingWeight(int n) {
        int noSetBits = 0;

        while(n)
        {
            n = n & (n-1);
            noSetBits++;
        }
        return noSetBits;
    }
};
```


> Time Complexity: O(t) [FASTER] (t ->  number of set bits)
>
> Space Complexity: O(1)