# Palindrome Pairs

Practice [Here](https://leetcode.com/problems/palindrome-pairs/description/)


```cpp
class Solution {
public:
    bool isPalindrome(string s1, string s2)
    {
        string s = s1+s2;
        int n = s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;

        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i!=j)
                {
                    if(isPalindrome(words[i], words[j]))
                        result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
```

| Complexity Type      | Value                |
| -------------------- | -------------------- |
| **Time Complexity**  | `O(n² * k)`          |
| **Space Complexity** | `O(n²)` (worst case) |
