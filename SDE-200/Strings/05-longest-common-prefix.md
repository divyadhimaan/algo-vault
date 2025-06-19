# Longest Common Prefix

Practice [Link](https://leetcode.com/problems/longest-common-prefix/description/)


Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

## Horizontal Scanning

- Idea: Start with the first string as prefix, compare it with the next, shrink it until it matches, repeat.
- Efficient when early mismatch is found.

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        
        string prefix = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            while(strs[i].find(prefix) != 0){
                prefix = prefix.substr(0, prefix.size()-1);
                if(prefix.empty())
                    return "";
            }
        }
        return prefix;
    }
};
```

> Time Complexity: O(S) (S = sum of all chars in all strings)	
>
> Space Complexity: O(1) or O(m) (for prefix)

## Vertical Scanning


- Idea: Compare characters column-wise (i.e., character at same index in each string).
- Best Case: All strings are identical → Fast
- Worst Case: Long strings with no common prefix → Slower
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        
        for(int i=0;i<strs[0].size();i++)
        {
            char ch = strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(i >= strs[j].size() || strs[j][i] != ch)
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
        
    }
};
```

> Time Complexity: O(S) (S = sum of all chars in all strings)	
>
> Space Complexity: O(1)

## Binary Search

- Idea: Binary search on the prefix length from 1 to the length of the shortest string.
- Optimized for large datasets.


```cpp
class Solution {
public:

    bool isCommonPrefix(vector<string>& strs, int len)
    {
        string prefix = strs[0].substr(0,len);
        for(int i=1;i<strs.size();i++)
        {
            if(strs[i].substr(0,len) != prefix)
                return false;
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";

        int minLen = strs[0].size();
        for(string s: strs)
            minLen = min(minLen, (int)s.size());

        int low = 1, high = minLen;
        while(low<=high)
        {
            int mid = (low+high)/2;

            if(isCommonPrefix(strs, mid))
                low = mid+1;
            else
                high = mid-1;
        }
        return strs[0].substr(0, (low+high)/2);
    }
};
```

> Time Complexity: O(s log m) (S = sum of all chars in all strings, m = min Length of strings)	
>
> Space Complexity: O(1)


## Trie Based Approach

- Pros: Structured, handles complex patterns	
- Cons: Extra space, more complex code

Build a Trie (prefix tree) with all strings, then walk down until a split (branch) or end of word is encountered.

## Selecting the right approach
| Situation                          | Best Approach          |
| ---------------------------------- | ---------------------- |
| Simple input or small string set   | Vertical or Horizontal |
| Large input size with long strings | Binary Search          |
| Need fast early rejection          | Horizontal             |
| Need optimized comparisons         | Binary Search          |
| Reuse or prefix-heavy problems     | Trie based             |
