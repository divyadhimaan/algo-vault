# Best Time to Buy and Sell Stock with transaction fee - VI

Practice [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)

You are given an array prices where `prices[i]` is the price of a given stock on the `ith` day, and an integer fee representing a `transaction fee`.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

> Note:
> - You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
> - The transaction fee is only charged once for each stock purchase and sale.


## Intiution
At any point we have two options, keeping in mind the transaction fee:
1. Buy a stock (only if previously not bought)
-   Do not sell - no transaction
-   sell stock
1. Sell a stock (only if previously bought)
-   Do not buy - no transaction
-   buy stock
   


## Recursive Approach
```cpp
class Solution {
public:
    int solve(vector<int> &prices, int idx, bool buy, int fee)
    {
        if(idx >= prices.size())
            return 0;
        
        int profit = 0;
        if(buy)
            profit = max(solve(prices, idx+1, 1, fee), -prices[idx] + solve(prices, idx+1, 0, fee));
        else
            profit = max(solve(prices, idx+1, 0, fee), prices[idx] - fee + solve(prices, idx+1, 1, fee));

        return profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, 0, 1, fee);
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
    int solve(vector<int> &prices, int fee, int idx, bool buy, vector<vector<int>> &memo)
    {
        if(idx >= prices.size())
            return 0;
        
        int profit = 0;

        if(memo[idx][buy] != -1)
            return memo[idx][buy];

        if(buy)
            profit += max(solve(prices, fee, idx+1, 1, memo), -prices[idx] + solve(prices, fee, idx+1, 0, memo));
        else
            profit += max(solve(prices, fee, idx+1, 0, memo), prices[idx] - fee + solve(prices, fee, idx+1, 1, memo));

        return memo[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> memo(prices.size(), vector<int>(2, -1));
        return solve(prices, fee, 0, 1, memo);
    }
};

```

> Time Complexity: O(2n)
>
> Space Complexity: O(2n) + O(n) (Recursive stack)


## Tabulation Approach

```cpp

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        dp[n][0] = 0;
        dp[n][1] = 0; 

        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                    profit += max(dp[idx+1][1], -prices[idx] + dp[idx+1][0]);
                else
                    profit += max(dp[idx+1][0], prices[idx] - fee + dp[idx+1][1]);
                dp[idx][buy] = profit;
            }
            
        }
        return dp[0][1];
    }
};
```

> Time Complexity: O(2n)
>
> Space Complexity: O(2n)


## Space Optimized

```cpp
class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> prev(2,0);
        vector<int> curr(2,0);

        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                    profit += max(prev[1], -prices[idx] + prev[0]);
                else
                    profit += max(prev[0], prices[idx]- fee + prev[1]);
                curr[buy] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
};

```
> Time Complexity: O(2n)
>
> Space Complexity: O(1)
