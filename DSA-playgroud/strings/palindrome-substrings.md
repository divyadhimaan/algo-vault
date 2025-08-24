# Plaindromic Substring

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
