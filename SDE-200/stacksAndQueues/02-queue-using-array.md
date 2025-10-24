# Queue Using Array

Practice [Link](https://www.geeksforgeeks.org/problems/implement-queue-using-array/1)


Implement a Queue using an Array. Queries in the Queue are of the following type:
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the popped element. If the queue is empty then return -1)



## Solution

```cpp
class ArrayQueue {
public:
    int* arrayQueue;
    int firstIdx;
    int lastIdx;
    int capacity;
    ArrayQueue() {
        capacity = 1000;
        arrayQueue = new int[capacity];
        firstIdx=0;
        lastIdx=-1;
    }
    
    void push(int x) {
        if(lastIdx == capacity-1)
            return;
        arrayQueue[++lastIdx] = x;
    }
    
    int pop() {
        if(isEmpty()){
            return -1;
        }
        int ele = arrayQueue[firstIdx++];

        if(firstIdx > lastIdx){
            firstIdx=0;
            lastIdx=-1;
        }
        return ele;
    }
    
    int peek() {
        if(isEmpty())
            return -1;
        return arrayQueue[firstIdx];
    }
    
    bool isEmpty() {
        return lastIdx==-1;
    }
};
```

> Time Complexity: 
>   - push - O(1)
>   - pop - O(1)
> 
> Space Complexity: O(n), 