# Insert Interval

Practice [Here](https://leetcode.com/problems/insert-interval/)

You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [starti, endi]` represent the start and the end of the `ith` interval and intervals is sorted in ascending order by `starti`. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.

Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `starti` and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return `intervals` after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.


## Brute Force: Linear Iteration

```cpp

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i=0;

        vector<vector<int>> newIntervals;

        // before overlapping, when end_i < start_new
        while(i<n && intervals[i][1] < newInterval[0]){
            newIntervals.push_back(intervals[i]);
            i++;
        }

        while(i<n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        newIntervals.push_back(newInterval);

        //after merging, add left intervals
        while(i<n){
            newIntervals.push_back(intervals[i]);
            i++;
        }
        return newIntervals;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)

## Better: Binary Search 


- Handle empty list:
  - If no intervals exist, return {newInterval}.
- Find first overlapping interval (startIdx):
  - Use binary search to find the first interval where end >= newInterval.start.
  - All intervals before this index are non-overlapping and go directly into the result.
- Find last overlapping interval (endIdx):
  - Use binary search to find the last interval where start <= newInterval.end.
  - All intervals after this index are non-overlapping and will be appended at the end.
- Add non-overlapping intervals before startIdx:
  - Push them to newIntervals.
- Merge all overlapping intervals:
  - Update newInterval.start = min(start) and newInterval.end = max(end) for all intervals from startIdx to endIdx.
- Push the merged newInterval into the result.
  - Add non-overlapping intervals after endIdx:
- Push them as they are to the result.

```cpp

class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0)
            return {newInterval};

        //Binary search for first overlapping interval
        int low = 0, high=n-1, startIdx=n;
        while(low<=high)
        {
            int mid = low + (high-low)/2;

            //end is not less than new start
            if(intervals[mid][1] >= newInterval[0]){
                startIdx = mid;
                high = mid-1;
            }else
                low = mid+1;
        }

        //Binary search for last overlapping interval
        low = 0, high=n-1;
        int endIdx=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;

            //start is less than new end
            if(newInterval[1] >= intervals[mid][0]){
                endIdx = mid;
                low = mid+1;
            }else
                high = mid-1;
        }

        vector<vector<int>> newIntervals;

        for(int i=0;i<startIdx;i++){
            newIntervals.push_back(intervals[i]);
        }

        while(startIdx<=endIdx)
        {
            newInterval[0] = min(newInterval[0], intervals[startIdx][0]);
            newInterval[1] = max(newInterval[1], intervals[startIdx][1]);
            startIdx++;
        }
        newIntervals.push_back(newInterval);

        for(int i=endIdx+1; i<n;i++){
            newIntervals.push_back(intervals[i]);
        }
        return newIntervals;
    }
};
```

> Time Complexity: O(n), Even though binary search has O(log n), the copying of intervals dominates
>
> Space Complexity: O(n)