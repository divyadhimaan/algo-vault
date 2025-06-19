# Best Time to Buy and Sell Stock - II

Practice [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/)

You are given an integer array prices where `prices[i]` is the price of a given stock on the `ith` day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.


## Intiution
At any point we have two options:
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
        if(idx == prices.size())
            return 0;
        
        int profit = 0;
        if(buy)
            profit += max(solve(prices, idx+1, 1), -prices[idx] + solve(prices, idx+1, 0));
        else
            profit += max(solve(prices, idx+1, 0), prices[idx] + solve(prices, idx+1, 1));

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
        if(idx == prices.size())
            return 0;
        
        int profit = 0;


        if(memo[idx][buy] != -1)
            return memo[idx][buy];

        if(buy)
            profit += max(solve(prices, idx+1, 1, memo), -prices[idx] + solve(prices, idx+1, 0, memo));
        else
            profit += max(solve(prices, idx+1, 0, memo), prices[idx] + solve(prices, idx+1, 1, memo));

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
                    profit += max(dp[idx+1][0], prices[idx] + dp[idx+1][1]);
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
                    profit += max(prev[0], prices[idx] + prev[1]);
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
