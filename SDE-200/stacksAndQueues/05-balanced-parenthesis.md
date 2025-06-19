# Balanced Parentheses

Practice [Link](https://leetcode.com/problems/valid-parentheses/)


Given a string s containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.
 

## Approach

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char c: s)
        {
            if(c == '(' || c == '{' || c == '[')
                stk.push(c);
            else{
                if(stk.empty() || (stk.top()=='(' && c!= ')') || (stk.top()=='{' and c!='}') || (stk.top() == '[' and c!= ']'))
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
```

> TC -> O(n)
>
> SC -> O(n)