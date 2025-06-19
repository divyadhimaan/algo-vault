# Best Time to Buy and Sell Stock with Cooldown - V

Practice [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)

You are given an array prices where` prices[i] `is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., `cooldown one day`).
> Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).




## Intiution
At any point we have two options just keep check for `cooldown time`:
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
    int solve(vector<int> &prices, int idx, bool buy)
    {
        if(idx >= prices.size())
            return 0;
        
        int profit = 0;
        if(buy)
            profit += max(solve(prices, idx+1, 1), -prices[idx] + solve(prices, idx+1, 0));
        else
            profit += max(solve(prices, idx+1, 0), prices[idx] + solve(prices, idx+2, 1));

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, 1);
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
    int solve(vector<int> &prices, int idx, bool buy, vector<vector<int>> &memo)
    {
        if(idx >= prices.size())
            return 0;
        
        int profit = 0;


        if(memo[idx][buy] != -1)
            return memo[idx][buy];

        if(buy)
            profit += max(solve(prices, idx+1, 1, memo), -prices[idx] + solve(prices, idx+1, 0, memo));
        else
            profit += max(solve(prices, idx+1, 0, memo), prices[idx] + solve(prices, idx+2, 1, memo));

        return memo[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, 1, memo);
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));
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
                    profit += max(dp[idx+1][0], prices[idx] + dp[idx+2][1]);
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2,0);
        vector<int> nextToNext(2,0);
        vector<int> curr(2,0);

        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                    profit += max(next[1], -prices[idx] + next[0]);
                else
                    profit += max(next[0], prices[idx] + nextToNext[1]);
                curr[buy] = profit;
            }
            nextToNext = next;
            next = curr;
        }
        return next[1];
    }
};
```
> Time Complexity: O(2n)
>
> Space Complexity: O(1)
