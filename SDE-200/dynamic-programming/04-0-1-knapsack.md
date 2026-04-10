# 0-1 Knapsack

Practice [Link](https://www.naukri.com/code360/problems/1072980?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website)

A thief is robbing a store and can carry a `maximum weight of ‘W’` into his `knapsack`. There are `'N' items` available in the store and the `weight and value` of each item is known to the thief. Considering the constraints of the maximum weight that a knapsack can carry, you have to find the maximum profit that a thief can generate by stealing items.
Note: The thief is not allowed to break the items.


For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with weight 6, 1 and 3. The total value of knapsack = 3 + 6 + 4 = 13.



Initution:

- We want to maximize the value.
- To pick an item 
  - If the weight of current item exceeds knapsack weight constraint -> ignore the item
  - else 
    - either pick the item and add the value
    - or dont pick and continue

## Recursive Approach

```cpp
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	if(n == 0 || w ==0)
		return 0;

	if(weights[n-1] > w)
		return maxProfit(values, weights, n-1, w);
	else
		return max(maxProfit(values, weights, n-1, w), values[n-1] + maxProfit(values, weights, n-1, w - weights[n-1]));
}
```
  
> Time Complexity: `O(2^n)` -> TLE
> 
> Space Compelexity: `O(n)`

## Memoized Approach

```cpp

int maxProfitUtil(vector<int> &values, vector<int> &weights, int n, int w, vector<vector<int>> &memo)
{
	if(n == 0 || w ==0)
		return 0;

	if(memo[n][w]!= -1)
		return memo[n][w];

	if(weights[n-1] > w)
		memo[n][w] = maxProfitUtil(values, weights, n-1, w, memo);
	else
		memo[n][w] = max(maxProfitUtil(values, weights, n-1, w, memo), values[n-1] + maxProfitUtil(values, weights, n-1, w - weights[n-1], memo));

	return memo[n][w];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> memo(n+1, vector<int>(w+1, -1));
	return maxProfitUtil(values, weights, n, w, memo);
}
```

> Time Complexity: `O(n*w)`
> 
> Space Compelexity: `O(n*w) + O(n)` -> recursive stack
>


## Tabulation


```cpp
int maxProfitUtil(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(weights[i-1] > j)
				dp[i][j] = dp[i-1][j];
			else	
				dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j-weights[i-1]]);
		}
	}
	return dp[n][w];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	return maxProfitUtil(values, weights, n, w);
}

```

> Time Complexity: `O(n*w)`, can perform worst than 2^n, for large `w` values
> 
> Space Complexity: `O(n*w)`


## Space Optimized - Tabulation

```cpp
class Solution{
    public:

        int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {

            // vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
            vector<int> curr(W + 1, 0), prev(W + 1, 0);


            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= W; j++){
                    if(wt[i-1] > j){
                        curr[j] = prev[j];
                    }else{
                        curr[j] = max(prev[j], val[i-1] + prev[j - wt[i-1]]);
                    }
                }
                prev = curr;
            }

            return curr[W];
        }
};
```

> Time Complexity: `O(n*w)`, can perform worst than 2^n, for large `w` values
>
> Space Complexity: `O(w)`

## Follow up - Return the indices of picked items

```cpp
#include <vector>
using namespace std;

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
  int n = items.size();
  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

  for(int i = 1; i <= n; i++){
      for(int j = 1; j <= capacity; j++){
        int wt = items[i-1][1];
        int val = items[i-1][0];
          if(wt > j){
              dp[i][j] = dp[i-1][j];
          }else{
              dp[i][j] = max(dp[i-1][j], val + dp[i-1][j - wt]);
          }
      }
  }

  int i = n, j = capacity;
  vector<int> pickedIndices;

  while (i > 0 && j > 0){
    if(dp[i][j] == dp[i-1][j])
      i -= 1;
    else{
      pickedIndices.push_back(i-1);
      j -= items[i-1][1];
      i -= 1;
    }
  }

  return {
    {dp[n][capacity]},    // total value
    pickedIndices,  // item indices
  };
}

```

> Time Complexity: `O(n*w) + O(n)`, 
>
> Space Complexity: `O(n*w)`