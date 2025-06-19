# Best Time to Buy and Sell Stock - III

Practice [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

You are given an array prices where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete at most `two` transactions.

> Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


## Intiution
At any point we have two options just keep check for the maximum possible transactions:
1. Buy a stock (only if previously not bought)
-   Do not sell - no transaction
-   sell stock
2. Sell a stock (only if previously bought)
-   Do not buy - no transaction
-   buy stock
   


## Recursive Approach

```cpp
class Solution {
public:

    int solve(vector<int> &prices, int idx, bool canBuy, int transactions)
    {
        if(transactions==0 || idx == prices.size())
            return 0;

        int profit = 0;

        if(canBuy)
            profit += max(solve(prices, idx+1, 1, transactions), -prices[idx] + solve(prices, idx+1, 0, transactions));
        else
            profit += max(solve(prices, idx+1, 0, transactions), prices[idx] + solve(prices, idx+1, 1, transactions-1));

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return solve(prices, 0,1, 2);
    }
};
```

> Time Complexity: O(2^n) --> TLE
>
> Space Complexity: O(n)


## Memoized Approach

Memoization stores already computed results in a dp array to avoid recalculations. This optimizes the recursive approach, reducing redundant computations while still exploring all possible outcomes.

```cpp
class Solution {
public:
    int solve(vector<int> &prices, int idx, bool canBuy, int transactions, vector<vector<vector<int>>> &memo)
    {
        if(transactions==0 || idx == prices.size())
            return 0;
        
        int profit = 0;

        if(memo[idx][canBuy][transactions] != -1)
            return memo[idx][canBuy][transactions];

        if(canBuy)
            profit += max(solve(prices, idx+1, 1,transactions, memo), -prices[idx] + solve(prices, idx+1, 0,transactions, memo));
        else
            profit += max(solve(prices, idx+1, 0,transactions, memo), prices[idx] + solve(prices, idx+1, 1,transactions-1, memo));

        return memo[idx][canBuy][transactions] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int transactions = 2;
        vector<vector<vector<int>>> memo(prices.size(), vector<vector<int>> (2, vector<int>(transactions+1, -1)));
        return solve(prices, 0, 1,transactions, memo);
    }
};
```

> Time Complexity: O(2 * 3 n) ~ O(n)
>
> Space Complexity: O(2 * 3 * n) + O(n) (Recursive stack)

## Tabulation

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int transactions = 2;
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>> (2, vector<int>(transactions+1, 0)));

        for(int idx=prices.size()-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int t=1;t<=2;t++)
                {
                    int profit=0;
                    if(buy)
                        profit = max(dp[idx+1][1][t], -prices[idx] + dp[idx+1][0][t]);
                    else
                        profit = max(dp[idx+1][0][t], prices[idx] + dp[idx+1][1][t-1]);
                    dp[idx][buy][t] = profit;
                }   
            }
        }

        return dp[0][1][2];
    }
};
```

> Time Complexity: O(2 * 3 n) ~ O(n)
>
> Space Complexity: O(2 * 3 * n)

## Space Optimized Tabulation

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int transactions = 2;

        vector<vector<int>> next(2, vector<int>(transactions+1, 0));
        vector<vector<int>> curr(2, vector<int>(transactions+1, 0));

        for(int idx=prices.size()-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int t=1;t<=2;t++)
                {
                    int profit=0;
                    if(buy)
                        profit = max(next[1][t], -prices[idx] + next[0][t]);
                    else
                        profit = max(next[0][t], prices[idx] + next[1][t-1]);
                    curr[buy][t] = profit;
                }   
            }
            next = curr;
        }

        return next[1][2];
    }
};
```

> Time Complexity: O(2 * 3 n) ~ O(n)
>
> Space Complexity: O(2 * 3)