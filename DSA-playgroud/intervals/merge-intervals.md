# Merge Intervals

Practice [here](https://leetcode.com/problems/merge-intervals/description/)

Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

## Linear scan


```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if(!ans.empty() && start > ans.back()[1])
                ans.push_back({start, end});
            else
                ans.back()[1] = max(end, ans.back()[1]);
        }

        return ans;
    }
};
```
> Time COmplexity: O(nlog n) + O(n)
>
> Space Complexity: O(n)

## Better approach: No extra Space

After sorting intervals by start time, all overlapping intervals will appear next to each other.
So we can scan left to right once and merge on the fly.
Think of it as painting a timeline:

- Start with the first interval → this is your current painted segment.
- Look at the next interval:
  - If it overlaps → extend your painted segment (merge).
  - If it doesn’t → lock the previous segment and start a new one.

> Why use `idx` -> write pointer?
- We are trying to merge in-place, not using a separate result vector.
- `idx` always points to the last merged interval in intervals[0..idx]

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int idx = 0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] <= intervals[idx][1]){
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
            } else{
                idx++;
                intervals[idx] = intervals[i];
            }
        }
        intervals.resize(idx+1);
        return intervals;
    }
};
```

> Time COmplexity: O(nlog n) + O(n)
>
> Space Complexity: O(1)