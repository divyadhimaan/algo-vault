# Matrix Chain Multiplication

Practice [Link](https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1)


Given an array `arr[]` which represents dimensions of sequence of matrices where the `ith` matrix has the dimensions `(arr[i-1] x arr[i])` for i>=1.
Find the most efficient way to multiply these matrices together. 
The efficient way is the one that involves the least number of multiplications.


## Intiution

This is a partition DP problem (Whenever we need to find the answer to a large problem such that the problem can be broken into subproblems and the final answer varies due to the order in which the subproblems are solved, we can think in terms of partition DP.)

Steps for partition DP
1. Start with entire block/ array (represent in terms of `(i,j)`, where i -> start index, j -> end index)
2. Try all partitions (run a loop)
3. return the best partition solution


Steps for MCM
F(i,j) = minimum multiplications to multiply matrix `i` -> matrix `j`
1. i = 1, j = n-1, where n is the size of the array -> `(i,j) = (1,n-1)`
2. Base case, if (i==j)
3. A loop(k) from i to j-1, first partition -> (i,k) and (k+1, j)
4. find multiplication for (i,j) => `arr[i-1] x arr[k] x arr[k] + f(i,k) + f(k+1, j)`
5. return minimum multiplications.


## Recursive Solution

```cpp
class Solution {
  public:
  
  int solve(vector<int> &arr, int i, int j)
  {
      if(i==j)
        return 0;
        
        int mini = 1e9;
        
        for(int k=i;k<=j-1;k++)
        {
            int steps = (arr[i-1] * arr[k] * arr[j]) + solve(arr, i, k) + solve(arr, k+1, j);
            mini = min(mini, steps);
        }
        return mini;
  }
  
    int matrixMultiplication(vector<int> &arr) {
        return solve(arr, 1, arr.size()-1);
    }
};
```

> O(2^n) -> TLE (Overlapping subproblems)


## Memoized Solution

```cpp
class Solution {
  public:
  
  int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
  {
      if(i==j)
        return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mini = 1e9;
        
        for(int k=i;k<=j-1;k++)
        {
            int steps = (arr[i-1] * arr[k] * arr[j]) + solve(arr, i, k, dp) + solve(arr, k+1, j, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
  }
  
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(arr, 1, n-1, dp);
    }
};
```

> Time Complexity: `O(n*n*n)`, states => n*n, partition loop O(n)
> 
> Space Compelexity: `O(n*n) + O(n)`