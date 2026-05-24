# Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

## Sliding Window - Fixed

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int nSize = s1.size();
        int mSize = s2.size();

        if(nSize > mSize)
            return false;

        vector<int> freqN(26), freqM(26);

        for(int i = 0; i < nSize; i++){
            freqN[s1[i]-'a']++;
            freqM[s2[i]-'a']++;
        }

        if(freqN == freqM)
            return true;

        for(int i=nSize; i<mSize; i++){
            freqM[s2[i]-'a']++;
            freqM[s2[i - nSize]-'a']--;

            if(freqN == freqM)
                return true;
        }
        return false;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)