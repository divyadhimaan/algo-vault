# Print all longest Common subsequence

Practice [Link](https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-all-lcs-sequences)


You are given two strings s and t. Now your task is to print all longest common sub-sequences in lexicographical order.


## Approach

```cpp
class Solution {
  public:
  
    void findAllLcs(string &s, string &t, int i, int j, vector<vector<int>> &dp, string curr, set<string> &res, map<string, bool>&memo)
    {
        //backtrack and find all LCS
        
        if(i==0 || j==0)
        {
            reverse(curr.begin(), curr.end());
            res.insert(curr);
            return;
            
        }
        
        string key = to_string(i) + '-' + to_string(j) + '-' + curr;
        if(memo.find(key) != memo.end())
            return;
            
        memo[key] = true;
        
        if(s[i-1] == t[j-1]){
            curr.push_back(s[i-1]);
            findAllLcs(s,t,i-1,j-1,dp, curr, res, memo);

        }else{
            if(dp[i][j] == dp[i-1][j])
                findAllLcs(s,t,i-1,j,dp, curr, res, memo);
            if(dp[i][j] == dp[i][j-1])
                findAllLcs(s,t,i,j-1,dp, curr, res, memo);
        }
    }
  
    vector<string> all_longest_common_subsequences(string s, string t) {
        int m = s.length(), n=t.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        
        set<string> res;
        string curr="";
        map<string, bool> memo;
        
        findAllLcs(s,t,m,n,dp, curr, res, memo);
        return vector<string>(res.begin(), res.end());
    }
    
};
```

> Time Complexity: O(m x n) + O(m x n)


## Tabulation

```cpp
#include <bits/stdc++.h>
using namespace std;

    void printLCS(vector<vector<int>> &dp, string &str, string str1, string str2){
        int i = str1.size();
        int j = str2.size();
        
        while(i>0 && j>0) {
          if(str1[i-1] == str2[j-1]){
              str = str1[i-1] + str;
              i--;
              j--;
          }else if(dp[i-1][j]>dp[i][j-1]){
              i--;
          }else{
              j--;
          }
      }
    }

    int lcsUtilDP(string str1, int m, string str2, int n, string &lcsStr){
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
    
      printLCS(dp, lcsStr, str1, str2);

      return dp[m][n];
    }

    int lcs(string str1, string str2, string &lcsStr) {
      int m = str1.size();
      int n = str2.size();
      return lcsUtilDP(str1, m, str2, n, lcsStr);
    }


int main() {
    string str1 = "bdefg";
    string str2 = "bfg";

    string lcsStr = "";

    cout<<lcs(str1, str2, lcsStr)<<" - "<<lcsStr<<endl;
    

    str1 = "mnop";
    str2 = "mnq";
    lcsStr = "";

    cout<<lcs(str1, str2, lcsStr)<<" - "<<lcsStr<<endl;

    return 0;
}
```

> Time Complexity: O(m x n) + O(m + n)
