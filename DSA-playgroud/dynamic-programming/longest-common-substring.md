# Longest common substring

Given two strings str1 and str2, find the length of their longest common substring.

A substring is a contiguous sequence of characters within a string.

## Intuition

The key difference from LCS (subsequence) is:
If characters don’t match at some point, the current length becomes 0 immediately.
- We compare characters of both strings:
  - If `str1[i-1] == str2[j-1]` => They can extend a continuous substring ending at `i-1` and `j-1`.
    - `dp[i][j] = dp[i-1][j-1] + 1`
  - If they don’t match => A continuous substring cannot continue.
    - `dp[i][j] = 0`

```cpp
class Solution{
    public: 
    int lcsUtilDP(string str1, int m, string str2, int n){
      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        int maxi = INT_MIN;
      for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
          if(str1[i-1]==str2[j-1]){
            dp[i][j] = dp[i-1][j-1] + 1;
          }else{
            dp[i][j] = 0;
          }
          maxi = max(maxi, dp[i][j]);
        }
      }
      return maxi;
    }
    int longestCommonSubstr (string str1, string str2){
      int m = str1.size();
      int n = str2.size();
      return lcsUtilDP(str1, m, str2, n);
    }
};

```

> Time Complexity: `O(m*n)` due to the nested loops iterating through the lengths of the two input strings.
> 
> Space Complexity: `O(m*n)` because the dp table of size (m+1)*(n+1) is created.