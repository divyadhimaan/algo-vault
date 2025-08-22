# Find Median from Data Stream

Practice [Link](https://leetcode.com/problems/find-median-from-data-stream/description/)


## Intiution

We want to efficiently maintain the median of a stream of numbers — i.e., support inserting numbers and finding the current median at any point.

The idea is to split the numbers into two halves:

- Left half (`leftHeap`): Max-heap → contains the smaller half of numbers.
- Right half (`rightHeap`): Min-heap → contains the larger half of numbers.

- Median is:
  - Top of leftHeap if total count is odd.
  - Average of tops of both heaps if total count is even.
  
  > Maintain two heaps (max-heap for left half, min-heap for right half) so numbers are balanced around the median, and median is always at the top(s).

```cpp
class MedianFinder {
public:
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(leftHeap.empty() || num <= leftHeap.top())
            leftHeap.push(num);
        else
            rightHeap.push(num);

        if(leftHeap.size() > rightHeap.size() + 1)
        {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }else if(leftHeap.size() < rightHeap.size())
        {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }
    
    double findMedian() {
        if(leftHeap.size() > rightHeap.size())
            return leftHeap.top();
        return (leftHeap.top() + rightHeap.top()) / 2.0;
    }
};

```

> Time Complexity:
> - Add() -> O(logn)
> - median() -> O(1)
>
> 
> Space Complexity: O(n)