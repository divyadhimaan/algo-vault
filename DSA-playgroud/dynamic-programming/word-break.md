# Word Break

Practice [here](https://leetcode.com/problems/word-break/description/)

Given a string `s` and a dictionary of strings `wordDict`, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



## Naive: Recursive Approach
```cpp
class Solution {
public:
    bool wordBreakUtil(string s, vector<string>& wordDict, int i)
    {
        if(i>=s.length())
            return true;

        for(string word: wordDict){
            int currWordLen = word.length();
            if(i+currWordLen <= s.length() && s.substr(i, currWordLen) == word)
                if(wordBreakUtil(s, wordDict, i+currWordLen))
                    return true;
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreakUtil(s, wordDict, 0);
    }
};
```

> Time Complexity: O(2<sup>n</sup>) --> TLE
>
> Space Complexity: O(n), recursion stack

## Memoization Approach

```cpp
class Solution {
public:
    bool wordBreakUtil(string s, vector<string>& wordDict, int i, vector<int> &memo)
    {
        if(i>=s.length())
            return true;

        if(memo[i] != -1)
            return memo[i];

        for(string word: wordDict){
            int currWordLen = word.length();
            if(i+currWordLen <= s.length() && s.substr(i, currWordLen) == word)
                if(wordBreakUtil(s, wordDict, i+currWordLen, memo))
                    return memo[i] = true;
        }
        return memo[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        return wordBreakUtil(s, wordDict, 0, memo);
    }
};
```

> Time Complexity: `O(n^2)` (each substring checked once).
>
> Space Complexity: `O(n) + O(n)`, recursion stack+ cache

## Tabulation Approach

```cpp
class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // dp[i]=true depicts that s[0...i-1] can be segmented
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j] && dict.count(s.substr(j, i-j))){
                    dp[i]= true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
```

> Time Complexity: `O(n^2)` (each substring checked once).
>
> Space Complexity: `O(n)`, cache

## BFS Approach

- Treat string as graph nodes (index = position in string).
- Start at index 0, push next indices where substring is valid.
- If reach n → return true.
> BFS can be useful when we want all segmentations too. 
```cpp
class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(0);
        while(!q.empty()){
            int start = q.front();
            q.pop();

            if(visited[start])
                continue;

            for(int end =start+1; end<=n; end++){
                if(dict.count(s.substr(start, end-start)))
                {
                    if(end==n)
                        return true;
                    q.push(end);
                }
            }
            visited[start] = true;
        }
        return false;

    }
};
```


> Time Complexity: `O(n^2)` (each substring checked once).
>
> Space Complexity: `O(n)`, cache

## Trie + DP: Optimization for large dict

- Build a Trie from wordDict.
- Traverse s while checking words via Trie.
- DP still needed but substring lookups become faster.
- optimize dictionary lookups.
# Comparison

| Approach                  | TC      | SC             | Pros                                              | Cons                          | When to Use                     |
| ------------------------- | ------- | -------------- | ------------------------------------------------- | ----------------------------- | ------------------------------- |
| Recursive (Naive)         | O(2^n)  | O(n)           | Easy to explain                                   | Useless for large input (TLE) | Just intuition                  |
| Memoization (Top-Down)    | O(n^2)  | O(n)           | Cleaner than naive                                | Uses recursion stack          | If interviewer pushes recursion |
| DP Tabulation (Bottom-Up) | O(n^2)  | O(n)           | Iterative, efficient, standard                    | Substring creation cost       | Best for interviews             |
| BFS (Graph View)          | O(n^2)  | O(n)           | Intuitive graph model, can extend to return paths | Slightly verbose              | When interviewer hints at graph |
| Trie + DP                 | O(n\*L) | O(n+dict size) | Optimized dict lookup                             | Extra coding effort           | Large dict, optimization focus  |
