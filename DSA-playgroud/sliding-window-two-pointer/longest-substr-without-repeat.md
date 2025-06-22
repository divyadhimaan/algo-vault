# Longest Substring Without Repeating Characters

Practice [Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

Given a string s, find the length of the longest substring without duplicate characters.


## Brute Force
```cpp
class Solution {
public:

    bool isValid(string s)
    {
        set<char> st;
        for(char c: s)
        {
            if(st.find(c) != st.end())
                return false;
            st.insert(c);
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        
        int maxLen = 0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                string str = s.substr(i, j-i+1);
                if(isValid(str))
                    maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};
```

> Time Complexity: O(n<sup>3</sup>)
>
> Space Complexity: O(n)

## Optimized Approach: SLiding Window

```cpp
class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seenChars;

        int maxLen = 0;
        int left =0 , right=0;

        while(right < s.length())
        {
            if(seenChars.find(s[right]) == seenChars.end())
            {
                seenChars.insert(s[right]);
                maxLen = max(maxLen, right-left+1);
                right++;
            }else{
                seenChars.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)