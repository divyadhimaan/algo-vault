# Counting Bits

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

## brute Force

```cpp
class Solution {
public:

    int hammingWeight(int n)
    {
        int noSetBits = 0;
        while(n)
        {
            if(n&1)
                noSetBits++;
            n = n>>1;
        }
        return noSetBits;
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            ans.push_back(hammingWeight(i));
        }
        return ans;
    }
};
```
> Time Complexity: O(n)
>
> Space Complexity: O(n)

## Dynamic Programming


```cpp

class Solution {
public:

    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=1;i<=n;i++){
            ans[i] = ans[i>>1] + (i&1);
        }
        return ans;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)