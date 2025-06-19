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

> Time Complexity - O(n)
> 
> Space Complexity - O(n)
 
