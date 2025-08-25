# Longest Palindromic Substring


## Naive Approach: Generate all substrings
```cpp
class Solution {
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int startIdx=0, longestLen  = 0;

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                int wordLen = j-i+1;
                if(isPalindrome(s.substr(i, wordLen))){
                    if(wordLen > longestLen){
                        startIdx = i, longestLen = wordLen;
                    }
                }
            }
        }
        return s.substr(startIdx, longestLen);
    }
};
```

> Time Complexity: O(n<sup>3</sup>)
>
> Space Complexity: O(1)

## Better Approach: Expand Around Center

- Key idea: A palindrome mirrors around its center.
- Each character (odd length) or gap between characters (even length) can be a center.
- Expand outward until not palindrome.
- There are 2n-1 centers.


```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int palindromicCount=0;

        auto expand = [&](int low, int high){
            while(low>=0 && high<n && s[low]==s[high]){
                palindromicCount++;
                low--,high++;
            }
        };

        for(int i=0;i<n;i++){
            expand(i,i);
            expand(i,i+1);
        }
        return palindromicCount;
    }
};
```

> Time Complexity: O(n<sup>2</sup>)
>
> Space Complexity: O(1)

