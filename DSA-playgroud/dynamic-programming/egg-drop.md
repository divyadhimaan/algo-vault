# Super Egg Drop

You are given `k` identical eggs and you have access to a building with `n` floors labeled from `1` to `n`.

You know that there exists a floor `f` where `0 <= f <= n `such that any egg dropped at a floor higher than `f` will break, and any egg dropped at or below floor `f` will not break.

Each move, you may take an unbroken egg and drop it from any floor `x` (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of `f` is.


## Memoized Solution

```cpp
class Solution {
public:

    int solve(int e, int f, vector<vector<int>> &memo)
    {
        if(f==0 || f==1 || e==1)
            return f;
            
        if(memo[e][f] != -1)
            return memo[e][f];
            
        int mini = INT_MAX;
            
        for(int k=1;k<=f;k++)
        {
            int attempts = 1 + max(solve(e-1, k-1, memo), solve(e, f-k, memo));
            mini = min(mini, attempts);
        }
        return memo[e][f] = mini;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> memo(k+1, vector<int>(n+1, -1));
        return solve(k, n, memo);
    }
};
```

> Time Complexity: `O(e x f x f)` --> Time Limit Exceeded
>
> Space Complexity: `O(e x f)`

## Binary Search

```cpp
class Solution {
public:

    int solve(int e, int f, vector<vector<int>> &memo)
    {
        if(f==0 || f==1 || e==1)
            return f;
            
        if(memo[e][f] != -1)
            return memo[e][f];
            
        int mini = INT_MAX;
        
        int low = 1, high = f;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            int breakCase = solve(e-1, mid-1, memo);
            int notBreakCase = solve(e, f-mid, memo);
            
            int attempts = 1 + max(breakCase, notBreakCase);
            mini = min(mini, attempts);
            
            if (breakCase > notBreakCase) {
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }
        return memo[e][f] = mini;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> memo(k+1, vector<int>(n+1, -1));
        return solve(k, n, memo);
    }
};
```

> Time Complexity: `O(e x f x logf)`
>
> Space Complexity: `O(e x f)`