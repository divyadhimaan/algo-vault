# Restore IP Addresses

Practice [link](https://leetcode.com/problems/restore-ip-addresses/description/)


## Backtracking Approach

```cpp
class Solution {
public:
    vector<string> ans;
    bool isValid(string &s, int i, int j)
    {
        if(j-i+1 > 3)
            return false;

        if(s[i]=='0' && j>i)
            return false;
        
        int num = stoi(s.substr(i, j-i+1));
        return num>=0 && num<=255;
    }
    

    void solve(string &s, int idx, int partCount, string &temp)
    {
        if(partCount==4 && idx==s.length())
        {
            ans.push_back(temp.substr(0, temp.length()-1));
            return;
        }
        if(partCount>=4 || idx>=s.length())
            return;

        for(int j=idx;j<idx+3 && j<s.length(); j++)
        {
            if(isValid(s, idx, j))
            {
                string text = temp;
                temp += s.substr(idx, j-idx+1) + '.';
                cout<<temp<<endl;
                solve(s, j+1, partCount+1, temp);
                temp = text;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.length() > 12 || s.length() < 4)
            return {};

        string temp="";
        solve(s, 0, 0, temp);
        return ans;
    }
};
```

> Time Complexity: O(3³) = O(27) per level × 4 levels