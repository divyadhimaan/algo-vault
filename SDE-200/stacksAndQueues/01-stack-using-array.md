# Stack Using Array

Practice [Link](https://www.geeksforgeeks.org/problems/implement-stack-using-array/1)


Write a program to implement a Stack using Array. Your task is to use the class as shown in the comments in the code editor and complete the functions `push()` and `pop()` to implement a stack. 

The `push()` method takes one argument, an integer 'x' to be pushed into the stack and `pop()` which returns an integer present at the top and popped out from the stack. If the stack is empty then return -1 from the `pop()` method.



## Solution

```cpp
class ArrayStack {
public:
    int* stackArray;
    int topIdx;
    int capacity;
    ArrayStack() {
        capacity = 10000;
        stackArray = new int[capacity];
        topIdx = -1;
    }
    
    void push(int x) {
        if(topIdx >= capacity){
            cout<<"Overflow"<<endl;
            return;
        }
        stackArray[++topIdx] = x;
    }
    
    int pop() {
        if(isEmpty()){
            return -1;
        }
        return stackArray[topIdx--];
    }
    
    int top() {
        if(isEmpty()){
            return -1;
        }
        return stackArray[topIdx];
    }
    
    bool isEmpty() {
        return topIdx==-1;
    }
};
```

> Time Complexity: 
>   - push - O(1)
>   - pop - O(1)
> 
> Space Complexity: O(n), 