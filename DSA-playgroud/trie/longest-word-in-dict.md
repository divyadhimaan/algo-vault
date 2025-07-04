# Longest Word in Dictionary

Practice [here](https://leetcode.com/problems/longest-word-in-dictionary/)

## Set Approach 
```cpp
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> st;

        string res="";

        for(string word: words)
        {
            int len = word.length();
            if(len==1 || st.count(word.substr(0, len-1))){
                if(len > res.length())
                    res = word;
                st.insert(word);
            }

        }
        return res;
    }
};
```

> Time Complexity: `O(nlogn + nL)`, n -> total words in dict, L -> is the average word length.
> - O(N log N) — for sorting the words.
> - O(N * L) — for checking prefix and inserting into the set, where L is the average word length.
> 
> Space Complexity: `O(nL)`

## Trie Based