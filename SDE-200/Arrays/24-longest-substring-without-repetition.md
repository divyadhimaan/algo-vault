# Longest Substring Without Repeating Characters

Practice [Link](https://www.interviewbit.com/problems/subarray-with-given-xor/)

Given a string s, find the length of the longest substring without duplicate characters.


```cpp
class Solution {
public:

    int max(int x, int y)
    {
        if(x>y)
            return x;
        return y;
    }

    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;

        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        
        for(int i=0;i<s.length();i++)
        {
            int j = i;

            while(j<s.length() && mp[s[j]]<1)
            {
                mp[s[j]]++;
                j++;
            }
            maxi = max(mp.size(), maxi);
            mp.clear();
        }
        return maxi;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)