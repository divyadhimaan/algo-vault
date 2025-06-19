# Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Practice [Link](https://leetcode.com/problems/climbing-stairs/description/)


## Implementation

### A. Recursive Approach
```cpp

class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
            return 1;
        if(n<0)
            return 0;

        return climbStairs(n-1) + climbStairs(n-2);
    }
};

```
> Time Complexity - O(2^n) -> TLE
> 
> Space Complexity - O(n)

### B. Tabulation Solution

```cpp
class Solution {
public:

    int climbStairs(int n) {
        if(n==0 || n==1)
            return 1;

        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};
```

> Time Complexity - O(n)
> 
> Space Complexity - O(n)
 

### Tabulation : Space Optimized

```cpp
class Solution {
public:

    int climbStairs(int n) {
        if(n==0 || n==1)
            return 1;

        int prev2 = 1, prev1 = 1, curr;

        for(int i=2;i<=n;i++)
        {
            curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};
```


> Time Complexity - O(n)
> 
> Space Complexity - O(1)