# Sum of Two Integers

Practice [here](https://leetcode.com/problems/sum-of-two-integers/)

Given two integers `a` and `b`, return the sum of the two integers without using the operators `+` and `-`.



## Intiution

We mimic how addition works at the binary level:

- `^` handles sum without carry (XOR)
- `&` handles carry, but we need to shift it left by 1 to add it in the correct position


1. Sum = a ^ b → adds bits without carry
2. Carry = (a & b) << 1 → compute carry and shift it left
3. Repeat until carry == 0

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            unsigned carry = unsigned(a&b)<<1;
            a = a^b;
            b = carry;
        }
        return a;
    }
};
```

> Time Complexity: O(1) (at most 32 iterations for 32-bit integers)
>
> Space Complexity: O(1)