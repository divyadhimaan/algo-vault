# Find Median from Data Stream

Practice [Link](https://leetcode.com/problems/find-median-from-data-stream/description/)

## Brute Force

store everything in a list → sort every time → pick median.



```cpp
class MedianFinder {
public:
    vector<int> nums;

    MedianFinder() {}

    void addNum(int num) {
        nums.push_back(num);
    }

    double findMedian() {
        sort(nums.begin(), nums.end());  // sort on each call
        int n = nums.size();
        if (n % 2 == 1) 
            return nums[n / 2];
        else 
            return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
};

```

> Time Complexity: TLE
> - Add(num) -> O(1)
> - findMedian() -> O(nlogn)

## Better Solution: Intiution

We want to efficiently maintain the median of a stream of numbers — i.e., support inserting numbers and finding the current median at any point.

The idea is to split the numbers into two halves:

- Left half (`leftHeap`): Max-heap → contains the smaller half of numbers.
- Right half (`rightHeap`): Min-heap → contains the larger half of numbers.

- Median is:
  - Top of leftHeap if total count is odd.
  - Average of tops of both heaps if total count is even.
  
  > Maintain two heaps (max-heap for left half, min-heap for right half) so numbers are balanced around the median, and median is always at the top(s).

## Implementation

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

## Follow Ups
> Q: If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

A: Since the range is small and bounded (0–100), we don’t really need heaps or balanced BSTs.
We can instead use counting / frequency array. 

#### Approach
- Maintain an array count[101] → count[i] stores how many times i has appeared.
- Maintain n = total count of numbers inserted.
- To find the median:
  - Walk through count[] and find the middle element(s) according to n.
  - If n is odd → median is the (n/2 + 1)-th element.
  - If n is even → median is average of (n/2)-th and (n/2+1)-th elements.
  
> Time Complexity: 
> - addNum: O(1)
> - findMedian: O(R) where R=101 (fixed, constant).
> Overall: O(1) amortized.

---
> Q: If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

A: So most numbers are small (bounded range), but occasionally you may get outliers (very large or negative).
We combine two strategies:
- Use a counting array for numbers in [0,100].
- Use a balanced structure (like two heaps) for numbers outside [0,100].

#### Approach

- Maintain:
  - count[101] → frequency of numbers in range [0,100].
  - leftHeap (max-heap) + rightHeap (min-heap) → to store outliers (<0 or >100).
  - n = total number of elements.
- addNum(num):
  - If 0 <= num <= 100: increment count[num].
  - Else: insert into heap (decide which heap based on balance, same as normal median-of-data-stream logic).
  - Increment n.
- findMedian():
  - If the median position(s) fall entirely within [0,100]:
    - Find via scanning count[] (at most 101 steps → O(1)).
  - If they fall in the outliers:
    - Compute using heaps (like standard two-heap solution).
  - If the split is between [0,100] and outliers:
    - Combine both sources carefully.