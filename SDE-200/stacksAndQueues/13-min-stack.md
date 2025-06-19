
# Implement Min Stack
Practice [Link](https://leetcode.com/problems/min-stack/description/)

```cpp
class MinStack {
public:
stack<pair<int,int>> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty())
            stk.push({val,val});
        else{
            pair<int,int> temp = stk.top();
            if(val < temp.second)
                stk.push({val, val});
            else
                stk.push({val, temp.second});
        }
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```