# Minimum Window Substring

Practice [here](https://leetcode.com/problems/minimum-window-substring/description/)

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.


## Brute Force Approach

Generate All substrings

1. **Try every starting index `i` in `s`**
   - Assume `s[i...]` might form a valid window.

2. **Expand window with `j`**
   - For every `j ≥ i`, check substring `s[i..j]`.
   - Keep a copy of frequency map of `t` → `tempMap`.

3. **Consume characters**
   - For each `s[j]`, decrement from `tempMap`.
   - If `s[j]` was needed (`tempMap[s[j]] > 0` before decrement), reduce `required`.
   - `required` = how many chars are still missing to match `t`.

4. **Check for valid window**
   - When `required == 0` → substring `s[i..j]` is valid.
   - Compare with current best (`minLen`) and update if smaller.
   - Break inner loop (since extending further only makes window larger).

5. **Continue for next `i`**
   - Repeat the above for all starting points.

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.length()<t.length())
            return "";
        vector<int> map(128,0);
        for(char c: t)
            map[c]++;

        int minLen = INT_MAX, startIdx = -1; 

        
        for(int i=0;i<s.length();i++)
        {
            vector<int> tempMap = map;
            int required = t.length();
            for(int j=i;j<s.length();j++)
            {
                if(tempMap[s[j]] > 0)
                    required--;

                tempMap[s[j]]--;

                if(required == 0){
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                        startIdx = i;
                    }
                    break;
                }
            }   
        }
        return (startIdx==-1) ? "" :s.substr(startIdx, minLen);

           
    }
};
```

> Time Complexity: O(n<sup>2</sup>) --> TLE
>
> Space Complexity: O(128) ~ O(1)

## Better Solution: Sliding Window

1. Build a frequency map for `t`
   - Suppose `t = "ABC"`.  
   - We need: `{ A:1, B:1, C:1 }`.  
   - This tells us which chars and how many we still need in the current window.
2. Expand the window (`end` pointer)
   - Start scanning `s` from left to right.
   - Each time you add `s[end]` into the window:
     - Decrease its need in the frequency map.
     - If that character was still required (`need > 0`), reduce `required` count.
   - Keep going until the window has **all required characters** → `required == 0`.
3. Contract the window (`start` pointer)
   - Now we’ve got a valid window. But it may not be the *smallest*.  
   - Try moving `start` forward while keeping the window valid.
   - Each time before invalidating the window:
     - Update `minLen` if this new window is smaller.
   - As soon as the window becomes invalid (`required > 0`), stop contracting.
4. Repeat
   - Continue expanding `end` to search for new valid windows.
   - Always contract `start` as much as possible whenever you get a valid window.
   - Track the best (smallest) window seen.
5. Return the best window
- If no valid window found → return `""`.  
- Otherwise → return substring `[startIdx, startIdx+minLen)`.


> - Expansion finds validity.
> - Contraction finds minimality.

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.length()<t.length())
            return "";
        vector<int> need(128,0);
        for(char c: t)
            need[c]++;

        int minLen = INT_MAX, startIdx = -1; 

        int start = 0, end =0;
        int required = t.length();
        while(end < s.length())
        {
            if(need[s[end]]>0)
                required--;

            need[s[end]]--;
            end++;

            while(required==0)
            {
                if(end-start < minLen)
                {
                    minLen = end-start;
                    startIdx = start;
                }
                need[s[start]]++;
                if(need[s[start]]>0)
                    required++;
                start++;
            }
        }
        return (startIdx==-1) ? "" :s.substr(startIdx, minLen);      
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(128) ~ O(1)