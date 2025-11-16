# Minimum insertions or deletions to convert string A to B

Given two strings str1 and str2, find the minimum number of insertions and deletions in string str1 required to transform str1 into str2.

Insertion and deletion of characters can take place at any position in the string.


## Tabulation Approach

```cpp
class Solution{
	public: 
    int lcsUtilDP(string str1, int m, string str2, int n){

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

      for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
          if(str1[i-1]==str2[j-1]){
            dp[i][j] = dp[i-1][j-1] + 1;
          }else{
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
        }
      }
      return dp[m][n];
    }
    
    int minOperations(string str1, string str2) { 
        int m = str1.size();
        int n = str2.size();

        int lcs = lcsUtilDP(str1, m, str2, n);

        // deletions in string A + insertions in string B
        return (m-lcs) + (n-lcs);
	} 
};

```

> Time Complexity: `O(m*n)` due to the nested loops in the lcsUtilDP function where m and n are the lengths of the two strings.
>
> Space Complexity: `O(m*n)` because of the 2D vector dp of size (m+1)*(n+1) used for dynamic programming.