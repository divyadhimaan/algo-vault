# Longest Repeating Character Replacement

Practice [Link](https://leetcode.com/problems/longest-repeating-character-replacement/description/)

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

## Btute Force

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;

            for (int j = i; j < n; j++) {
                freq[s[j] - 'A']++;
                maxFreq = max(maxFreq, freq[s[j] - 'A']);

                int windowSize = j - i + 1;
                int toReplace = windowSize - maxFreq;

                if (toReplace <= k)
                    maxLen = max(maxLen, windowSize);
            }
        }

        return maxLen;
    }
};

```

> Time Complexity - O(n<sup>2</sup>)
>
> Space Complexity - O(1)

## Optimal - Sliding Window Approach

1. Window-based Thinking
   - Since we’re looking for a substring (contiguous block), a **sliding window** approach is natural.  
   - The window `[i, j]` represents the substring currently under consideration.

2. Validity of a Window
   - In each window, track:
     - The **most frequent character count** → `freq[m]`
     - The number of characters that need replacement →  
       ```
       toReplace = windowSize - freq[m]
       ```
   - If `toReplace <= k`, the window is valid ✅.  
   - If `toReplace > k`, the window is invalid ❌ and we shrink it from the left (`i++`).

3. Why Only Track the Max Frequency Char?
   - For validity, we only need to know the **dominant character** in the window.  
   - Replacements will always target non-dominant characters.  
   - Hence, we update the **max frequency** on the fly whenever a new character overtakes.
  
4. Greedy Nature of Sliding Window
   - If the window becomes invalid (`toReplace > k`), moving the left pointer `i` always reduces the replacement need.  
   - This ensures we cover all possible substrings efficiently.


```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0, maxLen = 0;
        
        vector<int> freq(26, 0);
        int m = s[0]-'A'; //will track most freq char

        while(j<s.length())
        {
            freq[s[j]-'A']++;
            if(freq[s[j]-'A'] > freq[m]) //if new char is the most freq one
                m = s[j]-'A'; 

            int windowSize = j-i+1;

            int toReplace = windowSize - freq[m]; 
            if(toReplace <= k)
                maxLen = max(maxLen, windowSize);
            else{
                freq[s[i]-'A']--;
                i++;
            }
            j++;
        }
        return maxLen;
    }
};
```

> Time Complexity - O(n)
>
> Space Complexity - O(1)