# Find Median from Data Stream

Practice [Link](https://leetcode.com/problems/find-median-from-data-stream/description/)

The **median** is the middle value of a sorted list. For an odd-length list it's the center element; for even-length it's the average of the two middle elements.

The challenge here is that numbers arrive one at a time (a stream), so we need a data structure that supports both efficient insertion and efficient median lookup — without re-sorting from scratch every time.

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

**Step 1 — Route the number to the correct half:**
- If `num` belongs to the smaller half (≤ max of left), push to `leftHeap`.
- Otherwise push to `rightHeap`.

**Step 2 — Rebalance so sizes stay within 1 of each other:**
- If `leftHeap` grows more than 1 ahead of `rightHeap`, move its top to the right.
- If `rightHeap` ever overtakes `leftHeap`, move its top to the left.
- This invariant ensures the median is always at the top(s).

**Step 3 — Read median in O(1):**
- Odd total → `leftHeap` has one extra → return its top.
- Even total → tops of both heaps are the two middle elements → return their average.

```cpp
class MedianFinder {
public:
    priority_queue<int> leftHeap;                            // max heap — smaller half
    priority_queue<int, vector<int>, greater<int>> rightHeap; // min heap — larger half

    MedianFinder() {}
    
    void addNum(int num) {
        // step 1: route to correct half
        if (leftHeap.empty() || num <= leftHeap.top())
            leftHeap.push(num);
        else
            rightHeap.push(num);

        // step 2: rebalance
        if (leftHeap.size() > rightHeap.size() + 1) {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        } else if (leftHeap.size() < rightHeap.size()) {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }
    
    double findMedian() {
        if (leftHeap.size() > rightHeap.size())
            return leftHeap.top();
        return (leftHeap.top() + rightHeap.top()) / 2.0;
    }
};
```

> Time Complexity:
> - `addNum()` → O(log n) — at most 2 heap pushes/pops
> - `findMedian()` → O(1)
>
> Space Complexity: O(n)

## Follow Ups
> Q: If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

The two-heap solution is general — it works for any integers. But when the range is fixed and small, we’re doing more work than necessary. Heaps cost O(log n) per insertion just to maintain sorted order, but if we know every number is between 0 and 100, we can use that constraint directly.

**Key insight:** instead of storing the numbers themselves, store how many times each value has appeared. A `count[101]` frequency array gives us a compact, always-sorted view of all inserted numbers — for free.

`addNum` is just `count[num]++` → O(1).

For `findMedian`, we need to find the middle position(s) across all inserted numbers. We walk `count[]` left to right, accumulating a running total until we hit the target rank(s). Since the array is fixed at size 101, this walk is always at most 101 steps — effectively O(1).

```cpp
class MedianFinder {
    int count[101] = {};
    int n = 0;

public:
    void addNum(int num) {
        count[num]++;
        n++;
    }

    double findMedian() {
        int mid1 = (n + 1) / 2; // lower middle (works for both odd and even)
        int mid2 = (n + 2) / 2; // upper middle (same as mid1 when n is odd)

        int val1 = -1, val2 = -1, cumulative = 0;
        for (int i = 0; i <= 100; i++) {
            cumulative += count[i];
            if (val1 == -1 && cumulative >= mid1) val1 = i;
            if (val2 == -1 && cumulative >= mid2) val2 = i;
            if (val1 != -1 && val2 != -1) break;
        }
        return (val1 + val2) / 2.0;
    }
};
```

> Time Complexity:
> - `addNum` → O(1)
> - `findMedian` → O(101) = O(1) — range is fixed, not n
>
> Space Complexity: O(1) — count array is fixed size

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