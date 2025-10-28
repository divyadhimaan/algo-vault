# Longest Substring Without Repeating Characters

Practice [Link](https://www.interviewbit.com/problems/subarray-with-given-xor/)

Given a string s, find the length of the longest substring without duplicate characters.


## Brute Force

```cpp
class Solution{
  public:
    int longestNonRepeatingSubstring(string& s){
        int start=0, n = s.size();

        unordered_set<char> exploredChar;
        int maxLen = 0;

        for(int end=0;end<n;end++){
          char c = s[end];
          while(exploredChar.count(c)){
            exploredChar.erase(s[start]);
            start++;
          }

          exploredChar.insert(c);
          maxLen = max(maxLen, end-start+1);
        }
        return maxLen;
    }
};
```

> Time Complexity:O(n), where n is the length of the string, due to the single for loop and while loop which combined iterates at most n times.
> 
> Space Complexity:O(k), where k is the number of unique characters in the string, due to the unordered_set which stores characters. In the worst case, k can be equal to n, hence O(n).


## Better Approach

```cpp
class Solution{
  public:
    int longestNonRepeatingSubstring(string& s){
      if(s.length()==0)
        return 0;

        int start=0, n = s.size();

        vector<int> lastIndex(256, -1);
        int maxLen = INT_MIN;
        
        for(int end=0;end<n;end++){
          if(lastIndex[s[end]] >= start)
            start = lastIndex[s[end]]+1;

          lastIndex[s[end]] = end;

          maxLen = max(maxLen, end-start+1);
        }
        return maxLen;
    }
};
```

> Time Complexity:O(n) because the code iterates through the string 's' once using a single for loop.
> 
> Space Complexity:O(1) because the 'lastIndex' vector has a fixed size of 256, independent of the input string size.