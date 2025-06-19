# Minimum Add to Make Parentheses Valid

Practice [Link](https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1)


```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;

        int cnt=0;
        for(char c: s)
        {
            if(c=='(')
                stk.push(c);
            else if(c==')' && stk.empty())
                cnt++;
            else
                stk.pop();

        }
        return stk.size() + cnt;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)