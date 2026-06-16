# Kth Largest Element in an Array

Practice [Link](https://leetcode.com/problems/kth-largest-element-in-an-array/)

Given an integer array `nums` and an integer `k`, return the `kth` largest element in the array.

Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.


## Approach 1: Sort (Naive)

Sort in descending order, return the element at index `k-1`.

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};
```

> Time Complexity: O(n log n)
>
> Space Complexity: O(1)

---

## Approach 2: Max Heap

Push all elements into a max heap, then pop `k-1` times to discard the top `k-1` largest elements. The top is then the kth largest.

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; // max heap by default

        for (int num : nums)
            pq.push(num);

        while (k - 1 > 0) {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
```

**Why it works:** a max heap always surfaces the largest element at the top. Popping `k-1` times removes the 1st through (k-1)th largest, leaving the kth largest on top.

> Time Complexity: O(n log n) — building the heap is O(n), each of the k-1 pops costs O(log n)
>
> Space Complexity: O(n) — entire array lives in the heap

---

## Approach 3: Min Heap of Size k (Optimal)

Maintain a min heap of exactly `k` elements. For each new element, push it in; if the heap exceeds size `k`, pop the minimum. After processing all elements, the heap contains the `k` largest and the top is the kth largest.

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap

        for (int i = 0; i < k; i++)
            pq.push(nums[i]);

        for (int i = k; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k)
                pq.pop(); // evict the smallest — it can't be the kth largest
        }
        return pq.top();
    }
};
```

**Why it works:** the min heap acts as a sliding window of the `k` largest elements seen so far. The top is always the smallest among them — i.e., the kth largest overall. Any new element larger than the current top displaces it; smaller elements get evicted immediately.

**Why this beats the max heap approach:** the heap stays at size `k` instead of `n`, so each push/pop is O(log k) not O(log n).

> Time Complexity: O(n log k)
>
> Space Complexity: O(k)

---

## Comparison

|              | Sort       | Max Heap           | Min Heap of size k |
|--------------|------------|--------------------|--------------------|
| **Time**     | O(n log n) | O(n log n)         | O(n log k)         |
| **Space**    | O(1)       | O(n)               | O(k)               |
| **Best for** | Simplicity | Intuitive heap use | Large n, small k   |