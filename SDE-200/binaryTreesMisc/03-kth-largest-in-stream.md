# Kth Largest Element in a Stream

Practice [Link](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer `k`, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

`KthLargest(int k, int[] nums)`: Initializes the object with the integer k and the stream of test scores nums.

`int add(int val)`: Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.


## Brute Force -> Sorting + Set

```cpp
class KthLargest {
public:
    vector<int> nums;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
    }
    
    int add(int val) {
        nums.push_back(val);
        sort(nums.rbegin(), nums.rend());  // Sort in descending order
        return nums[k-1];  // k-th largest
    }
};
```

> Time Complexity: `O(nlogn)`, Very slow for large n, since sorting takes O(nlogn) each time
>
> Space Complexity: O(n)


## MinHeap Implementation

```cpp
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > sz)
            pq.pop();
        return pq.top();
    }
};
```

> Time Complexity: 
>  - Constructor: O(nlogk)
>  - Add: O(logk)
>
> Space Complexity: O(k)