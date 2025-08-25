# Palindromic Substring

Practice [here](https://leetcode.com/problems/palindromic-substrings/description/)

Given a string `s`, return the number of **palindromic substrings** in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string

## Brute Force: generate all substrings

- Generate all substrings `s[i...j]`.
- Check if each substring is a palindrome.
- Count the palindromes.
  
```cpp
class Solution {
public:

    bool isPalindrome(string s, int l, int r)
    {
        while(l<r){
            if(s[l++] != s[r--]) 
                return false;
        }
        return true;
    }

    int countSubstrings(string s) {
        int palindromeCount=0;

        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                if(isPalindrome(s, i,j))
                    palindromeCount++;
            }
        }
        return palindromeCount;
    }
};
```

> Time Complexity:` O(n<sup>3</sup>)`
> - Substring generation → **O(n²)**  
> - Palindrome check → **O(n)**  
>
> Space Complexity: `O(1)`

## Better Approach: Expansion on center

1. A palindrome expands equally around its center.
2. Each palindrome has a center at:
   - A character (odd-length palindrome). 
   - A gap between two characters (even-length palindrome).
3. For each center (total 2n-1 centers), expand while `s[l] == s[r]`.

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        for(int center=0; center<2*n-1; center++) {
            int l = center/2;
            int r = l + center%2;
            while(l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--; r++;
            }
        }
        return count;
    }
};
```

> Time Complexity:` O(n<sup>3</sup>)`
> - Centers → **O(n²)**  
> - Expansion → **O(n)**  
>
> Space Complexity: `O(1)`


## DP Approach

- Use a DP table: `dp[i][j] = true` if s[i...j] is a palindrome.
- Base cases:
  - Single char substrings → always palindrome.
  - Two chars → palindrome if s[i] == s[j].
- Transition:
  - d[i][j] = (s[i] == s[j]) && dp[i+1][j-1].

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int palindromeCnt=0;
        for(int len=1;len<=n;len++)
        {
            for(int i=0;i+len-1<n;i++)
            {
                int j = i + len-1;
                if(s[i]==s[j]){
                    if(len<=2)
                        dp[i][j]=true;
                    else
                        dp[i][j] = dp[i+1][j-1];
                }
                if(dp[i][j])
                    palindromeCnt++;
            }
        }
        return palindromeCnt;

    }
};
```


> Time Complexity:` O(n<sup>2</sup>)`
>
> Space Complexity: `O(n<sup>2</sup>)`