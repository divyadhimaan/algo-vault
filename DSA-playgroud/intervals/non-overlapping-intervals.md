# Non-overlapping Intervals

Practice [here](https://leetcode.com/problems/non-overlapping-intervals/description/)

Given an array of intervals `intervals` where `intervals[i] = [starti, endi]`, return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

## Problem gist

We are given a list of intervals.

- Goal: Remove the minimum number of intervals so that the remaining intervals do not overlap.
- Equivalent to: Find the maximum number of non-overlapping intervals and remove the rest.


## Greedy Approach

Think about a timeline:

- Each interval occupies a segment of time.
- If two intervals overlap, we cannot keep both.

> To maximize how many intervals we can keep, we should prefer the interval that ends first.
Why?

- An interval that ends earlier frees up space for future intervals.
- An interval that ends later blocks more upcoming intervals → leads to more removals.

```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        int countOverlapIntervals = 0, idx = 0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] < intervals[idx][1]){
                countOverlapIntervals++;
                if(intervals[i][1] < intervals[idx][1])
                    idx = i;
            }
            else{
                idx=i;
            }
        }
        return countOverlapIntervals;
    }
};
```

> Time Complexity: O(n log n) for sorting + O(n) for scanning
>
> Space Complexity: O(1)

## DP Approach

DP approach would be slower -> O(n<sup>2</sup>)