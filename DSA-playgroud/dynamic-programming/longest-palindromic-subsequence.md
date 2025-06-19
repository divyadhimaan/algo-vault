# Longest Palindromic Subsequence

Practice [Link](https://leetcode.com/problems/longest-palindromic-subsequence/description/)


Given a string `s`, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

## Intiution

- The Longest Palindromic Subsequence of a string S can be found by computing the Longest Common Subsequence (LCS) between `s` and its reversed version (`s'`).
- Since a palindrome reads the same forward and backward, the LCS of `s` and `s'` gives the longest subsequence that appears in both and is a palindrome

## Recursion



```cpp
class Solution {
public:
    string reverse(string s)
    {
        string temp="";
        for(char c: s)
        {
            temp = c + temp;
        }
        return temp;
    }

    int lcs(string s1, string s2, int m , int n)
    {
        if(m==0 || n==0)
            return 0;

        if(s1[m-1] == s2[n-1])
            return 1 + lcs(s1,s2,m-1,n-1);
        return max(lcs(s1,s2,m-1,n), lcs(s1,s2,m,n-1));
    }

    int longestPalindromeSubseq(string s) {
        string str = reverse(s);
        return lcs(s, str, s.length(), str.length());
    }
};
```

> O(2^n) -> TLE (Overlapping subproblems)


## Memoized DP

```cpp
class Solution {
public:
    string reverse(string s)
    {
        string temp="";
        for(char c: s)
        {
            temp = c + temp;
        }
        return temp;
    }

    int lcs(string s1, string s2, int m , int n, vector<vector<int>> &memo)
    {
        if(m==0 || n==0)
            return 0;

        if(memo[m][n] != -1)
            return memo[m][n];

        if(s1[m-1] == s2[n-1])
            memo[m][n] = 1 + lcs(s1,s2,m-1,n-1, memo);
        else
            memo[m][n] = max(lcs(s1,s2,m-1,n, memo), lcs(s1,s2,m,n-1, memo));

        return memo[m][n];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string str = reverse(s);
        vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
        return lcs(s, str, n, n, memo);
    }
};
```

> Time Complexity:  O(n^2) --> Still gives TLE
> 
> Space Compelexity:  O(n^2) + O(n) -> recursive stack

## Tabulation

```cpp
class Solution {
public:
    string reverse(string s)
    {
        string temp="";
        for(char c: s)
        {
            temp = c + temp;
        }
        return temp;
    }

    int lcs(string s1, string s2)
    {
        int n = s1.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }

    int longestPalindromeSubseq(string s) {
        
        string str = reverse(s);
        return lcs(s, str);
    }
};
```


> Time Complexity: O(n^2)
> 
> Space Compelexity: O(n^2)