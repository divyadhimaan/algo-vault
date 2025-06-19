# Roman to Int or vice versa

Practice Link [Roman to Int](https://leetcode.com/problems/roman-to-integer/description/), [Int to Roman](https://leetcode.com/problems/integer-to-roman/)

## Roman to Int
```cpp
class Solution {
public:
    int romanToInt(string s) {
        if(s.length()==0)
            return 0;
        
        unordered_map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int res =0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(table[s[i]] < table[s[i+1]])
                res -= table[s[i]];
            else
                res += table[s[i]];
        }
        res += table[s.back()];
        return res;
    }
};
```

> Time Complexity: O(N)
>
> Space COmplexity: O(1)

## Int to Roman

```cpp
class Solution {
public:
    string intToRoman(int num) {
        vector<int> values =    {1000, 900, 500, 400, 100, 90,  50,  40,  10, 9,   5,  4,  1};
        vector<string> symbols ={"M",  "CM","D", "CD","C","XC","L", "XL","X","IX","V","IV","I"};

        string result = "";
        for(int i=0;i<values.size();i++)
        {
            while(num >= values[i])
            {
                result += symbols[i];
                num -= values[i];
            }
        }
        return result;
    }
};
```