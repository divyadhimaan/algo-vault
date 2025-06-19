# Queue Using Array

Practice [Link](https://www.geeksforgeeks.org/problems/implement-queue-using-array/1)


Implement a Queue using an Array. Queries in the Queue are of the following type:
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the popped element. If the queue is empty then return -1)



## Solution

```cpp
/*

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

// Function to push an element x in a queue.
void MyQueue ::push(int x) {
    arr[rear++] = x;
    
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    if(front==rear)
        return -1;
        
    int val = arr[front];
    front=(front+1)%100005;
    return val;
}
```

> Time Complexity: 
>   - push - O(1)
>   - pop - O(1)
> 
> Space Complexity: O(n), 