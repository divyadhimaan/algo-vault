# Shortest common super-sequence

Given two strings str1 and str2, find the shortest common super-sequence.

The shortest common super-sequence is the shortest string that contains both str1 and str2 as subsequences.

## Intuition
- After computing the LCS DP table, we backtrack from `dp[m][n]`.
- Case 1: Characters match
- `s1[i-1] == s2[j-1]`
  - This character is part of the LCS.
  - So it must appear once in the SCS.
  - Move diagonally in the DP grid.
  - Add the character to the result.
- Case 2: Characters don’t match
- We choose the direction that gives a bigger LCS value (more optimal path):
- If coming from `dp[i-1][j]` (UP in the grid)
  - take `s1[i-1]`, move i--
- Else coming from `dp[i][j-1]` (LEFT in the grid)
  - take `s2[j-1]`, move j--
- This ensures no loss of characters from either string.
- After loop ends
- If one string finishes first, the remaining characters of the other must still be included — appended to the result.

```cpp
class Solution{
    public: 

    string findSuperSeq(vector<vector<int>> &dp, string s1, string s2){
        int i = s1.size();
        int j = s2.size();

        string res="";
        
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                res = s1[i-1] + res;
                i--;
                j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                res = s1[i-1] + res;
                i--;
            }else{
                res = s2[j-1] + res;
                j--;
            }
        }
        while (i > 0) {
            res = s1[i - 1] + res;
            i--;
        }
        while (j > 0) {
            res = s2[j - 1] + res;
            j--;
        }
        return res;
    }

    string lcsUtilDP(string str1, int m, string str2, int n){
      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

      for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
          if(str1[i-1]==str2[j-1]){
            dp[i][j] = dp[i-1][j-1] + 1;
          }else{
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
        }
      }
      string str = findSuperSeq(dp, str1, str2);
      return str;
    }

    string shortestCommonSupersequence(string str1, string str2){
        int m = str1.size();
        int n = str2.size();

        return lcsUtilDP(str1, m, str2, n);
    }
};
```
> Time Complexity: `O(m*n)` due to the nested loops in lcsUtilDP and findSuperSeq functions where m and n are the lengths of the input strings.
>
> Space Complexity: `O(m*n)` due to the 2D vector dp of size (m+1)*(n+1) used in lcsUtilDP function, where m and n are the lengths of the input strings.