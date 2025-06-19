## Coin Change II


Practice [Link](https://leetcode.com/problems/coin-change-ii/description/)


You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

## Recursive Version

```cpp
class Solution {
public:
    int changeUtil(int amount, int n, vector<int>&coins)
    {
        if(amount==0)
            return 1;
        if(n<0)
            return 0;

        int res = changeUtil(amount, n-1, coins);
        if(coins[n]<=amount)
            res += changeUtil(amount-coins[n], n, coins);

        return res;
    }

    int change(int amount, vector<int>& coins) {
        return changeUtil(amount, coins.size()-1, coins);
    }
};
```
> Time Complexity: `O(2^n)`, -> TLE
>
> Space Complexity: `O(n)`


## Memoized Version

```cpp
class Solution {
public:
    int changeUtil(int amount, int n, vector<int>&coins, vector<vector<int>> &memo)
    {
        if(amount==0)
            return 1;
        if(n<0)
            return 0;

        if(memo[amount][n]!=-1)
            return memo[amount][n];

        int res = changeUtil(amount, n-1, coins, memo);
        if(coins[n]<=amount)
            res += changeUtil(amount-coins[n], n, coins, memo);

        return memo[amount][n] = res;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(amount+1, vector<int>(n,-1));
        return changeUtil(amount, coins.size()-1, coins, memo);
    }
};
```

> Time Complexity: `O(n*A)`, where A -> amount
>
> Space Complexity: `O(n*A) +O(n)`

## Tabulation: 

```cpp
class Solution {
public:
    int changeUtil(int amount, int n, vector<int>&coins)
    {
        vector<vector<int>> dp(amount+1, vector<int>(n+1,0));

        for(int i=0;i<=n;i++)
            dp[0][i] = 1;

        for(int j=0;j<=amount;j++)
            dp[j][0] = 0;

        for(int i=1;i<=amount;i++)
        {
            for(int j=1;j<=n;j++)
            {
                long long not_take= dp[i][j-1];
                long long take = 0;
                if(coins[j-1]<=i)
                    take += dp[i-coins[j-1]][j];

                dp[i][j] = take + not_take;
            }
        }
        return dp[amount][n];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return changeUtil(amount, coins.size(), coins);
    }
};
```

> Time Complexity: `O(n*A)`, where A -> amount
>
> Space Complexity: `O(n*A)`
