# Subsets with sum k

Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Practice [Link](https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem)


```cpp
class Solution {
  public:
  
    int perfectSumUtil(vector<int>& arr, int idx, int target, vector<vector<int>> &memo)
    {
        if(idx<0)
            return target==0;
        
        if(memo[idx][target]!= -1)
            return memo[idx][target];
            
        int not_take = perfectSumUtil(arr, idx-1, target, memo);
        int take = 0;
        if(arr[idx]<=target)    
            take = perfectSumUtil(arr, idx-1, target-arr[idx], memo);
            
        return memo[idx][target] = (take + not_take);
    }
  
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        
        for(int i=0;i<n;i++)
            dp[i][0]= 1;
        
        if(arr[0] <= target)
            dp[0][arr[0]] = 1;
            
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                int not_take = dp[i-1][j];
                int take = 0;
                if(arr[i] <= j)
                    take = dp[i-1][j-arr[i]];
                    
                dp[i][j] = (take + not_take)%10e9;
            }
        }
        
        return dp[n-1][target];
    }
};
```


> Time Complexity - `O(n*k)`
> 
> Space Complexity - `O(n*k ) + O(n)`