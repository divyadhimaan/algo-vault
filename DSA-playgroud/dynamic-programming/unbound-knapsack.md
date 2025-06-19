# Knapsack with Duplicate Items

Practice [Link](https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items)


Given a set of items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

## Memoized Version

```cpp
class Solution {
  public:
  
    int solve(vector<int>& val, vector<int>& wt, int n, int W,vector<vector<int>> &memo )
    {
        
        if(n==0)
            return (W/wt[0]) * val[0];
            
        if(memo[n][W] != -1)
            return memo[n][W];
            
        int take = INT_MIN, not_take=INT_MIN;
        if(wt[n] > W)
            not_take = solve(val, wt, n-1, W, memo);
        else
            take = val[n] + solve(val, wt, n, W-val[n], memo);
            
        return memo[n][W] = max(take, not_take);
    
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> memo(n, vector<int> (capacity+1, -1));
        return solve(val, wt, n-1, capacity, memo);
    }
};
```

> Time Complexity: O(n x W)
>
> Space Complexity: O(n x W) + O(n) -> recursion stack