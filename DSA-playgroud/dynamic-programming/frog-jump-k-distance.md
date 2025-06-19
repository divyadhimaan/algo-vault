# Frog Jump with k distances
Given an array `arr[]` of size n, where` arr[i]` denotes the height of `ith` stone. Geek starts from stone 0 and from stone i, he can jump to stones `i + 1, i + 2, … i + k`. The cost for jumping from stone i to stone j is `abs(arr[i] – arr[j])`. Find the minimum cost for Geek to reach the last stone.

Practice [Link](https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost)


## Implementation

### Recursive

```cpp
class Solution {
  public:
  
    int minimizeCostUtil(int k, vector<int>& arr, int n)
    {
        if(n==0)
            return 0;
        
        int minCost = INT_MAX;
        for(int jumpSize = 1;jumpSize<=k;jumpSize++)
        {
            if(n-jumpSize >= 0){
                int jumpCost = minimizeCostUtil(k, arr, n-jumpSize) + abs(arr[n]-arr[n-jumpSize]);
                minCost = min(minCost,jumpCost);
            }
        }
        return minCost;
    }
  
    int minimizeCost(int k, vector<int>& arr) {
        return minimizeCostUtil(k, arr, arr.size()-1);
    }
};
```

> Time Complexity: O(k^n)


### Memoized Version

```cpp
class Solution {
  public:
  
    int minimizeCostUtil(int k, vector<int>& arr, int n, vector<int> &memo)
    {
        if(n==0)
            return 0;
            
        if(memo[n] != -1)
            return memo[n];
        
        int minCost = INT_MAX;
        for(int jumpSize = 1;jumpSize<=k;jumpSize++)
        {
            if(n-jumpSize >= 0){
                int jumpCost = minimizeCostUtil(k, arr, n-jumpSize, memo) + abs(arr[n]-arr[n-jumpSize]);
                minCost = min(minCost,jumpCost);
            }
        }
        return memo[n] = minCost;
    }
  
    int minimizeCost(int k, vector<int>& arr) {
        vector<int> memo(arr.size(), -1);
        return minimizeCostUtil(k, arr, arr.size()-1, memo);
    }
};

```

> Time Complexity: O(k*n)
>
> Space Complexity: O(n)

### Tabulation version

```cpp
int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0]=0;

        for(int i=1;i<n;i++)
        {
            int minCost = INT_MAX;
            for(int j=1;j<=k;j++)
            {
                if(i-j>=0)
                {
                    int jumpCost = dp[i-j] + abs(arr[i]-arr[i-j]);
                    minCost = min(minCost,jumpCost);
                }
            }
            dp[i] = minCost;
        }
        return dp[n-1];
        
    }
```

> Time Complexity: O(k*n)
>
> Space Complexity: O(n)