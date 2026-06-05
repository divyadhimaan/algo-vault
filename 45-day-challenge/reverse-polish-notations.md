# Evaluate Reverse Polish Notation

```cpp
class Solution {
public:
    int evaluate(int num1, int num2, string op){
        if(op == "+") return num1 + num2;
        if(op == "-") return num1 - num2;
        if(op == "*") return num1 * num2;
        if(op == "/") return num1 / num2;
        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        int t = tokens.size();

        if(t==1)
            return stoi(tokens[0]);

        stack<int> stk;
        int ans = 0;


        for(int i=0;i<t;i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                stk.push(stoi(tokens[i]));
            }
            else{
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();

                ans = evaluate(num1, num2, tokens[i]);
                stk.push(ans);
            }
        }
        return ans;
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(1)