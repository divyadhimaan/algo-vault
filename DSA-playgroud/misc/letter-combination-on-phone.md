# Letter Combinations of a Phone Number

```cpp
class Solution {
public:
    void findCombinations(string &digits, int idx, string &path, vector<string> &res, unordered_map<char, string> &phoneMap)
    {
        if(path.length()==digits.size()){
            res.push_back(path);
            return;
        }

        for(char ch: phoneMap[digits[idx]])
        {
            path.push_back(ch);
            findCombinations(digits, idx+1, path, res, phoneMap);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};

        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> res;
        string path = "";
        findCombinations(digits, 0, path, res, phoneMap);
        return res;
    }
};
```