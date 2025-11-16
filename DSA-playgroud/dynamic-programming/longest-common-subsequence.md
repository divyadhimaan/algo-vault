# Longest Common Subsequence

Practice [Link](https://leetcode.com/problems/longest-common-subsequence/description/)

Given two strings `text1` and `text2`, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, `"ace"` is a subsequence of `"abcde"`.
A common subsequence of two strings is a subsequence that is common to both strings.

## Intuition

- We try to match characters of both strings while maintaining the relative order.
- The key idea:
  - If last characters match, they definitely belong to the LCS → so include them and move both pointers left.
  - If they don't match, we have two options:
    - Skip a character from string1
    - Skip a character from string2
And choose the option giving the longer answer.


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

    int longestCommonSubsequence(string text1, string text2) {
        return lcs(text1, text2, text1.size(), text2.size());
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

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        return lcs(text1, text2, m, n, memo);
    }
};
```
> Time Complexity: O(m*n)
> 
> Space Compelexity: O(m*n) + O(n) -> recursive stack


## DP Approach

> dp[i][j] = LCS of first i characters of text1 and first j characters of text2


```cpp
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
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
};
```
> Time Complexity: O(m*n)
> 
> Space Compelexity: O(m*n)

## Space Optimized Tabulation

```cpp
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
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
};
```

> Time Complexity: O(m*n)
> 
> Space Compelexity: O(n)