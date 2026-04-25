# Valid Parentheses

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char c: s)
        {
            if(c=='(' || c=='{' || c=='[')
                stk.push(c);
            else {
                if(stk.empty() || (c==')' && stk.top()!='(') || (c=='}' && stk.top()!='{') || (c==']' && stk.top()!='['))
                    return false;
                stk.pop();
            }

        }
        return stk.empty();
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(n)