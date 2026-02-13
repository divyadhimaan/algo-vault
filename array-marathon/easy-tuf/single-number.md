# Single number

Given an array of nums of n integers. Every integer in the array appears twice except one integer. Find the number that appeared once in the array.


## Brute Force: hashmap

- note freq of all elements
- Iterate through hashmap, answer is the element with frequency 1

> Time Complexity: O(n) + O(n/2)
>
> Space Complexity: O(n/2)

## Optimal Solution: XOR

```cpp
class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        int xorR = 0;

        for(int i=0;i<nums.size();i++)
            xorR ^= nums[i];

        return xorR;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)