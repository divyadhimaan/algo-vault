# Longest Palindromic Substring

Practice [Link](https://leetcode.com/problems/longest-palindromic-substring/description/)

Given a string s, return the longest palindromic substring in s.


## Implementation

### Brute Force

- Find all possible substrings
- Check for each substring to be a palindrome 
  
> Time Complexity - `O(n^3)`
> - O(n^2) -> find substrings
> - O(n) -> check palindrome
>
> Space Complexity - O(1)

### Better Approach

- Instead of finding the palindrome from start idx, its better to find the center of the susbtsring and expand to check for palindrome.

```cpp
class Solution {
public:
    string res = "";
    int resLen = 0;
    void findPalindrome(int l, int r, string s)
    {
        while(l >= 0 && r < s.length() && s[l]==s[r])
        {
            int currLen = r-l+1;
            if(currLen > resLen)
            {
                res = s.substr(l, r-l+1);
                resLen = currLen;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        

        for(int i=0;i<s.length();i++)
        {
            // For odd length
            findPalindrome(i, i, s);

            // For even length
            findPalindrome(i, i+1, s);

        }
        return res;
    }
};
```

> Time Complexity: O(n^2), For every char we are expanding and checking for plaindrome.
>
> Space Coomplexity: O(1)

### Dynamic Programming Approach

- Useful when you want to track all palindromic substrings, not just the longest one -> can store all the palindromes.
- Explicitly stores subproblem solutions
- But O(n^2) space → heavy on memory

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0)
            return "";

        vector<vector<bool>> dp(n , vector<bool> (n, false));
        int maxLen = 1;
        int start = 0;

        // For substring of length 1
        for(int i=0;i<n;i++)
            dp[i][i] = true;

        // For substring of length 2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // For substring of length >= 3
        for(int len = 3;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                int j = i + len -1;
                
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};
```

> Time Complexity: O(n^2), For every char we are expanding and checking for plaindrome.
>
> Space Coomplexity: O(n^2)

## Comparison

| Approach             | Time  | Space | Complexity | Use When                            |
| -------------------- | ----- | ----- | ---------- | ----------------------------------- |
| Expand Around Center | O(n²) | O(1)  | Simple     | Best balance of simplicity & speed  |
| Dynamic Programming  | O(n²) | O(n²) | Medium     | Need to cache or analyze substrings |
