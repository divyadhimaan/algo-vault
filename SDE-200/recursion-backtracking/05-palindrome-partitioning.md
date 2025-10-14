# Palindrome partitioning

Given a string s partition string s such that every substring of partition is palindrome. Return all possible palindrome partition of string s.

## Intuition

| Concept                             | Role                                               |
|-------------------------------------|----------------------------------------------------|
| **Recursion index (`idx`)**         | Tracks the start of the next substring to consider |
| **Loop over `i` from `idx` to n-1** | Explores all possible substrings starting at `idx` |
| **Palindrome check**                | Ensures only valid substrings are added            |
| **Backtracking (pop_back)**         | Removes last substring to explore other partitions |
| **Base case (`idx==n`)**            | Partition is complete → add to result              |


## Implementation

```cpp
class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void findAllPartitions(string s, vector<vector<string>> &allPartitions, vector<string> currPartitions, int idx){
        if(idx==s.length()){
            allPartitions.push_back(currPartitions);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPalindrome(s, idx, i)){
                currPartitions.push_back(s.substr(idx, i-idx+1));
                findAllPartitions(s, allPartitions, currPartitions, i+1);
                currPartitions.pop_back();
            }
        }
    }

    vector<vector<string> > partition(string s) {
        vector<vector<string>> allPartitions;
        vector<string> currPartitions;

        findAllPartitions(s, allPartitions, currPartitions, 0);
        return allPartitions;
    }
};
```

> Time Complexity: O(n * 2^n) due to the recursive calls and palindrome checks.
> 
> Space Complexity: O(n)