# Stack Using Array

Practice [Link](https://www.geeksforgeeks.org/problems/implement-stack-using-array/1)


Write a program to implement a Stack using Array. Your task is to use the class as shown in the comments in the code editor and complete the functions `push()` and `pop()` to implement a stack. 

The `push()` method takes one argument, an integer 'x' to be pushed into the stack and `pop()` which returns an integer present at the top and popped out from the stack. If the stack is empty then return -1 from the `pop()` method.



## Solution

```cpp
/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack ::push(int x) {
    arr[++top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    if(top != -1)
    {
        int num = arr[top];
        top--;
        return num;
    }
    return -1;
}
```

> Time Complexity: 
>   - push - O(1)
>   - pop - O(1)
> 
> Space Complexity: O(n), 