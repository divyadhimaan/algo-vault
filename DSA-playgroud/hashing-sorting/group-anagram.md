# Group Anagrams

Practice [Link](https://leetcode.com/problems/group-anagrams/)
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

## Sorting + Hashing
- Sorting each string to use as a key in a hash map.
- Grouping original strings into a map where the sorted version is the key.
- Returning the grouped anagrams.

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(string s: strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());

            hash[temp].push_back(s);
        }

        vector<vector<string>> result;
        for(auto &it: hash)
        {
            result.push_back(it.second);
        }
        return result;
    }
};
```
> Time Complexity: `O(n * klogk)`, n = number of strings in strs, k = maximum length of a string
>
> Space Complexity: `O(n * k)`, 


## character counts Based key
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(string s: strs)
        {
            vector<int> count(26, 0);
            for (char c : s)
                count[c - 'a']++;

            // Create a unique key from character counts
            string key="";
            for (int i = 0; i < 26; ++i) {
                key += "#" + to_string(count[i]); // '#' to separate digits properly
            }

            cout<<"string: "<<s<<" key: "<<key<<endl;

            hash[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto &it: hash)
        {
            result.push_back(it.second);
        }
        return result;
    }
};
```

> Time Complexity: `O(n * k)`, n = number of strings in strs, k = maximum length of a string
>
> Space Complexity: `O(n * k)`, 