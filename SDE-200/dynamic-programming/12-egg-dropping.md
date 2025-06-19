# Egg Dropping Problem

Practice [Link](https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1)

You are given n identical eggs and you have access to a `k-floored` building from `1` to `f`.

There exists a floor `f'` where `0 <= f' <= f` such that any egg dropped from a floor higher than `f'` will break, and any egg dropped from or below floor `f'` will not break.
There are few rules given below. 

- An egg that survives a fall can be used again.
- A broken egg must be discarded.
- The effect of a fall is the same for all eggs.
- If the egg doesn't break at a certain floor, it will not break at any floor below.
- If the egg breaks on a certain floor, it will break on any floor above.


Return the minimum number of moves you need to determine the value of `f'` with certainty.


## Intiution

- We have to find the threshold floor `f` such that, 
  - for all `f''` > `f'` egg would definitely break 
  - for all `f''` <= `f'` egg would never break
- But the problem is not to find the threshold floor `f'`, but to find the minimum number of moves needed to determine `f'`.


- We will try every floor starting from `0` to `k` and look for `f'` but we have limited number of eggs available


Problem Breakdown: In worst case using the best technique, we have to find the minimum number of moves to determine `f'`

- Try to visualize the MCM pattern
  - find `i` and `j`: i = 1 and j = number of floors, `solve(e,f)`
  - base case: 
    - `e = 1` => result: `f`
    - `f = 1` => result: `f`
  - loop `(k): (1 -> f)`
  - At any step we have 2 options, we will take max of both for worst case:
    - if egg breaks at `kth` floor, `solve(e-1, k-1)`
    - if egg doesnt break, `solve(e, f-k)`
  

## Recursive Solution

```cpp
class Solution {
  public:
    int solve(int e, int f)
    {
        if(f==0 || f==1 || e==1)
            return f;
            
        int mini = INT_MAX;
            
        for(int k=1;k<=f;k++)
        {
            int attempts = 1 + max(solve(e-1, k-1), solve(e, f-k));
            mini = min(mini, attempts);
        }
        return mini;
    }
    
    int eggDrop(int n, int k) {
        return solve(n,k);
    }
};
```

> Time Complexity: `O(2^f)`

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
    
    int eggDrop(int n, int k) {
        vector<vector<int>> memo(n+1, vector<int>(k+1, -1));
        return solve(n,k, memo);
    }
};
```

> Time Complexity: `O(e x f x f)`
>
> Space Complexity: `O(e x f)`


## Binary Search

This above memoized solution can be further optimized by using binary search tenchnique while selecting the floor.

```cpp
class Solution {
  public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    
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
    
    int eggDrop(int n, int k) {
        vector<vector<int>> memo(n+1, vector<int>(k+1, -1));
        return solve(n,k, memo);
    }
};
```

> Time Complexity: `O(e x f x logf)`
>
> Space Complexity: `O(e x f)`