# Find All Anagrams in a String

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

## Sliding Window - Fixed
```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int sSize = s.size();
        int pSize = p.size();

        if(pSize > sSize)
            return result;

        vector<int> freqP(26), freqS(26);

        for(int i=0;i<pSize;i++){
            freqP[p[i]-'a']++;
            freqS[s[i]-'a']++;
        }

        if(freqP == freqS)
            result.push_back(0);

        for(int i = pSize; i < sSize; i++ ){
            freqS[s[i]-'a']++;
            freqS[s[i-pSize]-'a']--;

            if(freqP == freqS)
                result.push_back(i - pSize + 1);
            
        }
        return result;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)