# Minimum Insertion Steps to Make a String Palindrome

Practice [Link](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/)


Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

## Intiution

- In order to minimize the insertions, we need to find the length of the longest palindromic component or in other words, the longest palindromic subsequence.

- Minimum Insertion required = n(length of the string) - length of longest palindromic subsequence.

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
        int lcsLength = lcs(s, str, s.length(), str.length());
        return s.length()-lcsLength;
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
        int lcsLength = lcs(s, str, n, n, memo);
        return n - lcsLength;
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
    int minInsertions(string s) {
        int n = s.length();
        string str = reverse(s);
        int lcsLength = lcs(s,str);

        return n - lcsLength;
    }
};


```


> Time Complexity: O(n^2)
> 
> Space Compelexity: O(n^2)


## Space Optimized

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
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1] == s2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return curr[n];
    }
    int minInsertions(string s) {
        int n = s.length();
        string str = reverse(s);
        int lcsLength = lcs(s,str);

        return n - lcsLength;
    }
};


```

> Time Complexity: O(n^2)
> 
> Space Complexity: O(n)