# Implement Queue using Stacks

Practice [Link](https://leetcode.com/problems/implement-queue-using-stacks/description/)



Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
`void push(int x)` Pushes element x to the back of the queue.
`int pop()` Removes the element from the front of the queue and returns it.
`int peek()` Returns the element at the front of the queue.
`boolean empty()` Returns true if the queue is empty, false otherwise.


```cpp
class MyQueue {
public:
    stack<int> stk1,stk2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!stk1.empty())
        {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk1.push(x);

        while(!stk2.empty())
        {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
    
    int pop() {
        if(!empty()){
            int temp = stk1.top();
            stk1.pop();
            return temp;
        }
        return -1;
    }
    
    int peek() {
        return stk1.top();
    }
    
    bool empty() {
        return stk1.empty();
    }
};

```

> Time Complexity: 
> - push: O(n)
> - pop: O(1)
>
> Space Complexity: O(n)