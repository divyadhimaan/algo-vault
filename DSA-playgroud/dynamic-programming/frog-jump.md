# Frog Jump

Given an integer array `height[]` where `height[i] `represents the height of the `i-th` stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the `(i+1)th` stair or the `(i+2)th` stair. 

The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

Practice [Link](https://www.geeksforgeeks.org/problems/geek-jump/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)


## Implementation

### A. Recursive Approach
```cpp

int minCostUtil(vector<int>& height, int n)
  {
      if(n==0)
        return 0;
        
        
        int jumpOne = minCostUtil(height, n-1) + abs(height[n]-height[n-1]);
        int jumpTwo = INT_MAX;
        if(n>1)
            jumpTwo = minCostUtil(height, n-2) + abs(height[n]-height[n-2]);
            
        return min(jumpOne, jumpTwo);
  }
    
  
    int minCost(vector<int>& height) {
        return minCostUtil(height, height.size()-1);
    }

```
> Time Complexity - O(2^n) -> TLE
> 
> Space Complexity - O(n)

### B. Recursive Approach

```cpp
class Solution {
public:
    int frogJumpUtil(vector<int>& heights, int idx, vector<int> &memo) {
        if(idx==0)
            return 0;

        if(memo[idx]!= -1)
            return memo[idx];
        
        int jumpOne = abs(heights[idx]-heights[idx-1]) + frogJumpUtil(heights, idx-1, memo);

        int jumpTwo = INT_MAX;
        if(idx>1)
            jumpTwo = abs(heights[idx]-heights[idx-2]) + frogJumpUtil(heights, idx-2, memo);

        return memo[idx] = min(jumpOne, jumpTwo);
    }


    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> memo(n, -1);
        return frogJumpUtil(heights, n-1, memo);
    }
};
```

> Time Complexity - `O(n)` because each subproblem is solved only once due to memoization.
>
> Space Complexity - `O(n)` due to the memoization array and the recursion depth.

### B. Tabulation Solution

```cpp
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n);
        dp[0]=0;
        
        for(int i=1;i<n;i++)
        {
            int jumpOne = dp[i-1] + abs(height[i]-height[i-1]);
            int jumpTwo = INT_MAX;
            if(i>1)
                jumpTwo = dp[i-2] + abs(height[i]-height[i-2]);
            dp[i] = min(jumpOne, jumpTwo);
        }
        
        return dp[n-1];  
    }
```

> Time Complexity - `O(n)`
> 
> Space Complexity - `O(n)`
 
### D. Space Optimized Tabulation Solution

```cpp
class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();

        if(n==1)
            return 0;

        int prev2 = 0;
        int prev1 = 0;
        int curr;
        for(int i=1;i<n;i++){
            int jumpOne = abs(heights[i]-heights[i-1]) + prev1;
            int jumpTwo = INT_MAX;

            if(i>1)
                jumpTwo = abs(heights[i]-heights[i-2]) + prev2;

            curr = min(jumpOne, jumpTwo);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
        
    }
};
```

> Time Complexity - `O(n)`
>
> Space Complexity - `O(1)`