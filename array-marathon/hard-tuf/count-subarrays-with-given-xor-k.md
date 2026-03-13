# Count subarrays with given xor K

Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.


## Brute Force

```cpp
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            int x = k;
            for(int j = i; j < n; j++){
                x ^= nums[j];
                if(x==0)
                    count++;
            }
        }
        return count;
    }
};
```

> Time Complexity: O(n^2)
>
> Space Complexity - O(1)

## Better Approach