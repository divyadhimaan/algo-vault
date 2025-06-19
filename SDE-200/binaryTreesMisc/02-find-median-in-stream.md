# Find Median in Data Stream

Practice [Link](https://leetcode.com/problems/find-median-from-data-stream/description/)


The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

`MedianFinder() `initializes the MedianFinder object.
`void addNum(int num)` adds the integer num from the data stream to the data structure.
`double findMedian()` returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.


## Naive Approach

A naive approach is to store numbers in a `vector<int> vec`, and after every insertion, sort the array to get the median.
Sorting takes `O(n log n)`, which is too slow. 



## Better Solution - Two Heaps



### 1. How Do We Maintain the Median?

If we could efficiently track the middle element(s) of a growing list, finding the median would be easy.
The median splits numbers into two halves:
- Smaller half (left side of the median)
- Larger half (right side of the median)

> Hint: Two separate heaps can store each half!

- Max Heap (for the left half, to quickly get the largest number in the smaller half).
- Min Heap (for the right half, to quickly get the smallest number in the larger half).

Now, the median will always be:
- If odd count: The max of the left heap.
- If even count: The average of the max in left heap and min in right heap.
> 💡 This means that after each insertion, we only need to check the top of two heaps to find the median in O(1) time! 

### 2. Ensuring Balanced Heaps

If one heap becomes larger than the other, the median won’t be correct.

So, we balance the heaps:
- If `left.size() > right.size() + 1`, move the top of left to right.
- If `right.size() > left.size()`, move the top of right to left.

Now, the heaps stay balanced, and findMedian() is always` O(1)`.


```cpp
class MedianFinder {
public:
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
    MedianFinder() {}
    
    void addNum(int num) {
        if(leftHeap.empty() || num <= leftHeap.top())
            leftHeap.push(num);
        else
            rightHeap.push(num);

        if(leftHeap.size() > rightHeap.size() + 1){
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }else if(leftHeap.size() < rightHeap.size()){
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

>


> Time Complexity: O(logn)
> - addNum() -> O(logn)
> - findMedian() -> O(1)
>
> Space Complexity: O(n)