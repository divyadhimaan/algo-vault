# Permutations of a String

Given a string s, return **all unique permutations** of its characters in **sorted order**.
- The output should be a list of strings, where each string is a valid permutation of s.
- If the string contains duplicate characters, each permutation should appear only once.
- The list should be sorted lexicographically.

You must return a list of strings, where each string is a valid permutation of s.

## Intuition

- We use backtracking with in-place swapping:
  - Fix one character at a time (by swapping it to the current index). 
  - Recursively permute the rest of the string. 
  - Backtrack (swap back) to restore original state.
- This approach avoids extra memory and builds permutations efficiently.

## Implementation

```cpp
class Solution {
public:
    void permuteUniqueUtil(string &s, vector<string> &result, int idx)
    {
        if(idx==s.length()-1){
            result.push_back(s);
            return;
        }

        unordered_set<char> used;

        for(int i=idx;i<s.size();i++)
        {

            if(used.find(s[i]) != used.end())
                continue;

            used.insert(s[i]);

            swap(s[idx], s[i]);
            permuteUniqueUtil(s, result, idx+1);
            swap(s[idx], s[i]);
        }
    }

    vector<string> permuteUnique(string s) {
        vector<string> result;

        permuteUniqueUtil(s, result, 0);
        sort(result.begin(), result.end());
        return result;
    }
};

```

> Time Complexity: O(n! * n) due to generating all permutations and sorting the result
> 
> Space Complexity: O(n! * n) to store all unique permutations in the result vector, where each permutation has length n