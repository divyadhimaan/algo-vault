# Best Time to Buy and Sell Stock - IV

Practice [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)

You are given an integer array prices where `prices[i]` is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

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

    int maxProfit(int k, vector<int>& prices) {
        return solve(prices, 0,1, k);
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

    int solve(vector<int>& prices, int idx, bool canBuy, int transactions, vector<vector<vector<int>>> &memo)
    {
        if(transactions==0 || idx==prices.size())
            return 0;

        if(memo[idx][canBuy][transactions]!=-1)
            return memo[idx][canBuy][transactions];

        int profit = 0;

        if(canBuy)
            profit += max(solve(prices, idx+1, 1, transactions, memo), -prices[idx]+solve(prices, idx+1, 0, transactions, memo));
        else    
            profit += max(solve(prices, idx+1, 0, transactions, memo), prices[idx]+solve(prices, idx+1, 1, transactions-1, memo));

        return memo[idx][canBuy][transactions] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> memo(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices, 0, 1, k, memo);
    }
};
```

> Time Complexity: O(2 * k *  n) ~ O(kn)
>
> Space Complexity: O(2 * k * n) + O(kn) (Recursive stack)

## Tabulation

```cpp
class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int idx = prices.size()-1;idx>=0;idx--)
        {
            for(int canBuy=0;canBuy<=1;canBuy++)
            {
                for(int t = 1;t<=k;t++)
                {
                    int profit=0;
                    if(canBuy)
                        profit = max(dp[idx+1][1][t], -prices[idx]+dp[idx+1][0][t]);
                    else    
                        profit = max(dp[idx+1][0][t], prices[idx]+dp[idx+1][1][t-1]);

                    dp[idx][canBuy][t] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};
```

> Time Complexity: O(2 * k * n) ~ O(kn)
>
> Space Complexity: O(2 * k * n)

## Space Optimized Tabulation

```cpp
class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));


        for(int idx = prices.size()-1;idx>=0;idx--)
        {
            for(int canBuy=0;canBuy<=1;canBuy++)
            {
                for(int t = 1;t<=k;t++)
                {
                    int profit=0;
                    if(canBuy)
                        profit = max(next[1][t], -prices[idx]+next[0][t]);
                    else    
                        profit = max(next[0][t], prices[idx]+next[1][t-1]);

                    curr[canBuy][t] = profit;
                    next = curr;
                }
            }
        }
        return next[1][k];
    }
};
```

> Time Complexity: O(2 * k * n) ~ O(kn)
>
> Space Complexity: O(2 * k)