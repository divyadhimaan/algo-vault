# Subset Sum equal to target

Given an array of positive integers arr[] and a value target, determine if there is a subset of the given array with sum equal to given target. 


Practice [Link](https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1)


## Recursion Solution

```cpp
class Solution {
  public:
  
    bool isSubsetSumUtil(vector<int> &arr, int idx, int target)
    {
        if(target==0)
            return true;
        if(idx<0)
            return false;
        bool not_take = isSubsetSumUtil(arr, idx-1, target);
        bool take = false;
        if(arr[idx] <=target)
            take = isSubsetSumUtil(arr, idx-1, target-arr[idx]);
        return take || not_take;
    }
  
    bool isSubsetSum(vector<int>& arr, int target) {
        return isSubsetSumUtil(arr, arr.size()-1, target);
    }
};
```

> Time Complexity - `O(2^n)`
> 
> Space Complexity - `O(n)`


## Memoized Solution

```cpp
class Solution {
  public:
  
    bool isSubsetSumUtil(vector<int> &arr, int idx, int target, vector<vector<int>> &memo)
    {
        if(target==0)
            return true;
        if(idx<0)
            return false;
            
        if(memo[idx][target] != -1)
            return memo[idx][target];
        
        bool not_take = isSubsetSumUtil(arr, idx-1, target, memo);
        bool take = false;
        if(arr[idx] <=target)
            take = isSubsetSumUtil(arr, idx-1, target-arr[idx], memo);
        return memo[idx][target] = take || not_take;
    }
  
    bool isSubsetSum(vector<int>& arr, int target) {
        vector<vector<int>> memo(arr.size(), vector<int>(target+1, -1));
        return isSubsetSumUtil(arr, arr.size()-1, target, memo);
    }
};
```

> Time Complexity - `O(n*k)`
> 
> Space Complexity - `O(n*k ) + O(n)`

## Tabulation Solution

```cpp
class Solution {
  public:
  
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        
        for(int i=0; i<n; i++)
            dp[i][0] = true;
        
        if(arr[0] <= target)
            dp[0][arr[0]] = true;
            
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<=target; j++)
            {
                bool not_take = dp[i-1][j];
                bool take = false;
                if(arr[i] <= j)
                    take = dp[i-1][j-arr[i]];
                    
                dp[i][j] = take || not_take;
            }
        }
        
        
        return dp[n-1][target];
    }
};
```

> Time Complexity - `O(n*k)`
> 
> Space Complexity - `O(n*k )`