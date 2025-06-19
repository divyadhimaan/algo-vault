# Rod Cutting

Practice [Link](https://www.geeksforgeeks.org/problems/rod-cutting0840/1)

Given a rod of length n(size of price) inches and an array of prices, price. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.


## Memoized Approach

```cpp
class Solution {
  public:
  
  int solve(int idx,int n, vector<int> &price, vector<vector<int>> &memo)
    {
        if(idx==0)
            return n * price[0];
        if(memo[idx][n]!= -1)
            return memo[idx][n];
            
        int notTake = solve(idx-1, n, price, memo);
        
        int take = INT_MIN;
        int rodLength = idx+1;
        if(rodLength <= n)
            take = price[idx] + solve(idx, n-rodLength, price, memo);
            
        return memo[idx][n] = max(take, notTake);
    }
  
    int cutRod(vector<int> &price) {
        int n = price.size();
       vector<vector<int>> memo(n, vector<int>(n+1, -1));
        return solve(n-1, n, price, memo);
    }
};
```

> Time Complexity: O(n x n)
>
> Space Complexity: O(n x n) + O(n)

## tabulation Approach

```cpp
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
        for(int j=0;j<=n;j++)
        {
            dp[0][j] = j*price[0];
        }
       
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<=n;j++)
           {
               int notTake = dp[i-1][j];
        
                int take = INT_MIN;
                int rodLength = i+1;
                
                if(rodLength <= j)
                    take = price[i] + dp[i][j-rodLength];
                
                
                dp[i][j] = max(take, notTake);
           }
       }
       
       
        return dp[n-1][n];
    }
};
```

> Time Complexity: O(n x n)
>
> Space Complexity: O(n x n)


## Space Optimized Solution

```cpp
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> prev(n+1, 0), curr(n+1,0);
        
        for(int j=0;j<=n;j++)
        {
            prev[j] = j*price[0];
        }
       
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<=n;j++)
           {
               int notTake = prev[j];
        
                int take = INT_MIN;
                int rodLength = i+1;
                
                if(rodLength <= j)
                    take = price[i] + curr[j-rodLength];
                
                
                curr[j] = max(take, notTake);
           }
           prev = curr;
       }
       
        return prev[n];
    }
};
```

> Time Complexity: O(n x n)
>
> Space Complexity: O(n)