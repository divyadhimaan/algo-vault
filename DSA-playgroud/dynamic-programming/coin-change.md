## Coin Change


Practice [Link](https://leetcode.com/problems/coin-change/description/)


You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.


## Memoized Version

```cpp
class Solution {
public:
    int solve(vector<int> &coins, int idx, int amount, vector<vector<int>> &memo)
    {
        if(idx<0 || amount<=0)
        {
            return (amount==0) ? 0 : INT_MAX -1;
        }

        if(memo[idx][amount]!= -1)
            return memo[idx][amount];

        int not_take = solve(coins, idx-1, amount, memo);
        int take = 1e9;
        if(coins[idx] <= amount)
            take = 1 + solve(coins, idx, amount-coins[idx], memo);

        return memo[idx][amount] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> memo(n, vector<int> (amount+1, -1));
        int ans = solve(coins, n-1, amount, memo);
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};
```

> Time Complexity: `O(n*A)`, where A -> amount
>
> Space Complexity: `O(n*A) +O(n)`

## Tabulation: 2-D

```cpp
class Solution {
public:
    int solveTabulation(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1));

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = (j==0) ? 0 : INT_MAX-1;
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                int not_take = dp[i-1][j];
                int take = INT_MAX-1;
                if(coins[i-1] <= j)
                    take = 1 + dp[i][j-coins[i-1]];
                dp[i][j] = min(take, not_take);
            }
        }

        return dp[n][amount];
    }


    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        

        int ans = solveTabulation(coins, amount);
        if(ans == INT_MAX -1)
            return -1;
        return ans;
    }
};
```

> Time Complexity: `O(n*A)`, where A -> amount
>
> Space Complexity: `O(n*A)`

## DP Approach 1-D

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);

        dp[0]=0;

        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(coins[j]<=i)
                {
                    int res= dp[i-coins[j]];
                    if(res!=INT_MAX)
                        dp[i] = min(dp[i], res+1);
                }
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
};
```

> Time Complexity: `O(n*A)`, where A -> amount
>
> Space Complexity: `O(A)`

| Problem Type                               | Use 1D or 2D?              |
| ------------------------------------------ | -------------------------- |
| **Unlimited coins (unbounded knapsack)**   | ✅ 1D is enough             |
| **Limited supply (0/1 knapsack)**          | ❌ Use 2D DP                |
| **Track combinations/subsets with states** | ❌ Use 2D DP                |
| **Need to reconstruct choices**            | ❌ Use 2D (or parent array) |
