# Implement Stack using Queues

Practice [Link](https://leetcode.com/problems/implement-stack-using-queues/description/)



Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

`void push(int x)` Pushes element x to the top of the stack.
`int pop() `Removes the element on the top of the stack and returns it.
`int top()` Returns the element on the top of the stack.
`boolean empty()` Returns true if the stack is empty, false otherwise.


```cpp
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        q1 = q2;
        q2= queue<int>();
    }
    
    int pop() {
        if(!empty()){
            int temp = q1.front();
            q1.pop();
            return temp;
        }
        return -1;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

```

> Time Complexity: 
> - push: O(n)
> - pop: O(1)
>
> Space Complexity: O(n)