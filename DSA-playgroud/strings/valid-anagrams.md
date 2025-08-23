# Valid Anagrams

Practice [here](https://leetcode.com/problems/valid-anagram/description/)

Given two strings `s` and `t`, return true if `t` is an anagram of `s`, and false otherwise.

## Brute Force: Sorting


```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s==t;
    }
};
```

> Time Complexity: O(nlogn)
>
> Space Complexity: O(1)

## Better Approach: Hash Map

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        unordered_map<char, int> freqMap;

        for(char c: s)
            freqMap[c]++;

        for(char c: t){
            if(!freqMap.count(c) || --freqMap[c]<0)
                return false;
        }


        return true;

    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)

## Better Approach: For fixed characters

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        vector<int> freqList(26, 0);

        for(char c: s)
            freqList[c-'a']++;

        for(char c: t){
            if(--freqList[c-'a']<0)
                return false;
        }

        return true;

    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)