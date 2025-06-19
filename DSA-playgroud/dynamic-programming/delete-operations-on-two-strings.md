# Delete Operation for Two Strings

Practice [Link](https://leetcode.com/problems/delete-operation-for-two-strings/description/)

Given two strings `word1` and `word2`, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.


## Brute Force

- Find all the subsequences of both strings and compare

> O(2^(m + n)) -> TLE (Overlapping subproblems)

## Recursive 

```cpp
class Solution {
public:
    int lcs(string text1, string text2, int m, int n)
    {
        if(m==0 || n==0)
            return 0;

        if(text1[m-1] == text2[n-1])
            return 1 + lcs(text1, text2, m-1, n-1);

        return max(lcs(text1, text2, m-1, n), lcs(text1, text2, m, n-1));
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int lcsLength = lcs(word1, word2, m, n);

        return (m+n) - (2*lcsLength);
    }
};
```

> O(2^n) -> TLE (Overlapping subproblems)

## Memoized DP Approach

```cpp
class Solution {
public:
    int lcs(string text1, string text2, int m, int n, vector<vector<int>> &memo)
    {
        if(m==0 || n==0)
            return 0;

        if(memo[m][n] != -1)
            return memo[m][n];

        if(text1[m-1] == text2[n-1])
            memo[m][n] = 1 + lcs(text1, text2, m-1, n-1, memo);
        else
            memo[m][n] = max(lcs(text1, text2, m-1, n, memo), lcs(text1, text2, m, n-1, memo));
            return memo[m][n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        int lcsLength = lcs(word1, word2, m, n, memo);

        return (m+n) - (2*lcsLength);
    }
};
```
> Time Complexity: O(m*n)
> 
> Space Compelexity: O(m*n) + O(n) -> recursive stack


## DP Approach


```cpp
class Solution {
public:
    int lcs(string text1, string text2, int m, int n)
    {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
             }
        }

        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int lcsLength = lcs(word1, word2, m, n);

        return (m+n) - (2*lcsLength);
    }
};
```
> Time Complexity: O(m*n)
> 
> Space Compelexity: O(m*n)

## Space Optimized Tabulation

```cpp
class Solution {
public:
    int lcs(string text1, string text2, int m, int n)
    {
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);


        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1] == text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
             }
             prev = curr;
        }

        return prev[n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int lcsLength = lcs(word1, word2, m, n);

        return (m+n) - (2*lcsLength);
    }
};
```

> Time Complexity: O(m*n)
> 
> Space Compelexity: O(n)