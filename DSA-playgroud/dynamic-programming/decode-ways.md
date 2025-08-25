# Decode Ways

Practice [here](https://leetcode.com/problems/decode-ways/description/)
Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

## Brute Force: Recursion + Backtracking
```cpp
class Solution {
public:
    int dfs(string s, int i)
    {
        if(i==s.size())
            return 1;
        if(s[i]=='0')
            return 0;

        int ways = dfs(s, i+1);
        if(i+1< s.size() && stoi(s.substr(i, 2))<=26)
            ways += dfs(s, i+2);
        return ways;
    }

    int numDecodings(string s) {
        return dfs(s, 0);
    }
};

```

> Time Complexity: O(2<sup>n</sup>)
>
> Space Complexity: O(n)

## DP Solution: Tabulation

```cpp
class Solution {
public:

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n]=1;

        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!='0'){
                dp[i] = dp[i+1];
                if(i+1<n && stoi(s.substr(i, 2))<=26)
                    dp[i]+= dp[i+2];
            }
        }
        return dp[0];

    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)

## DP Solution: Tabulation - Space Optimized


```cpp
class Solution {
public:

    int numDecodings(string s) {
        int n = s.size();
        int next1 =1, next2=0;
        int curr=0;

        for(int i=n-1;i>=0;i--)
        {
            curr=0;
            if(s[i]!='0'){
                curr = next1;
                int two = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if(i+1<n && two>=10 && two<=26)
                    curr+= next2;
            }
            next2 = next1;
            next1 = curr;
        }
        return curr;
    }
};

```


> Time Complexity: O(n)
>
> Space Complexity: O(1)