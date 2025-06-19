# Edit Distance

Practice [Link](https://leetcode.com/problems/edit-distance/submissions/1531612926/)


Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

- Insert a character
- Delete a character
- Replace a character





## Recursive 

```cpp
class Solution {
public:
    int eD(string s1, string s2, int m, int n)
    {
        if(m==0)
            return n;
        if(n==0)
            return m;
        if(s1[m-1] == s2[n-1])
            return eD(s1, s2, m-1, n-1);
        else 
            return 1 + min(eD(s1, s2, m, n-1), min(eD(s1, s2, m-1, n), eD(s1, s2, m-1, n-1)));
    }
    
    int minDistance(string word1, string word2) {
        return eD(word1, word2, word1.length(), word2.length());
    }
};
```

> O(3^n) -> TLE (Overlapping subproblems)


## DP Approach


```cpp
class Solution {
public:
    int eD2(string s1, string s2, int m, int n)
    {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        for(int i=0;i<=m;i++)
            dp[i][0] = i;
        
        for(int j=0;j<=n;j++)
            dp[0][j] = j;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        return eD2(word1, word2, word1.length(), word2.length());
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

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);

        for(int j=0;j<=n;j++)
            prev[j] = j;
        
        for(int i=1;i<=m;i++)
        {
            curr[0] = i;
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                else
                    curr[j] = 1 + min(curr[j-1], min(prev[j-1], prev[j]));
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
