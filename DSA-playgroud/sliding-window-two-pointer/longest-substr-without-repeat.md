# Longest Substring Without Repeating Characters

Practice [Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

Given a string s, find the length of the longest substring without duplicate characters.


## Brute Force

- Generate all substrings.
- Check each substring for duplicates using a set or frequency array.
- Track the longest valid substring.
  
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

## Better Approach

- Fix a starting index i.
- Extend substring to the right (j) while storing seen chars in a set.
- Break when a duplicate is found.
- Update max length as you go.

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;

        for(int i=0;i<s.length();i++)
        {
            set<char> st;
            for(int j=i;j<s.length();j++)
            {
                if(st.count(s[j]))
                {
                    maxLen = max(maxLen, j-i);
                    break;
                }
                st.insert(s[j]);
                maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};
```
> Time Complexity: O(n<sup>2</sup>)
>
> Space Complexity: O(n)

## Optimized Approach: SLiding Window with Set

- Maintain a sliding window [start, end] with unique characters.
- Use a set to store current window chars.
- Expand end. If duplicate is found, remove s[start] and move start until valid again.
- Update max length at each step.
  
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;

        int start = 0;
        unordered_set<char> seenChars;
        for(int end=0;end<s.length();end++)
        {
            while(seenChars.count(s[end])){
                seenChars.erase(s[start++]);
            }
            seenChars.insert(s[end]);
            maxLen = max(maxLen, end-start+1);
        }
        return maxLen;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(min(n, charset))

## Best in Practice: Sliding Window with map of Last Seen

- Instead of shrinking window one by one, directly jump left pointer using last seen index.
- Use `unordered_map<char, int>` → stores last index of each char.
- When duplicate at `end`, set `start = max(start, lastIndex[s[end]] + 1)`.

Note: We always ensure `start` never moves backward. (use case `s = "abba"`)
- max() ensures `start` only moves forward when needed.
- Without max, window may include stale duplicates.

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;
        
        unordered_map<char, int> seenCharIdx;

        for(int end=0;end<s.length();end++)
        {
            if(seenCharIdx.find(s[end]) != seenCharIdx.end()){
                start = max(start, seenCharIdx[s[end]]+1);
            }
            seenCharIdx[s[end]]=end;
            maxLen = max(maxLen, end-start+1);
        }
        return maxLen;

    }
};
```



> Time Complexity: O(n)
>
> Space Complexity: O(min(n, charset))

> NOTE: If charset is fixed (like ASCII 128 or extended 256), we can use an array instead of map for constant-time lookups.