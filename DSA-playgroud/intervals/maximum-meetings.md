# Maximum meetings

Pratice [here](https://www.naukri.com/code360/problems/maximum-meetings_1062658?interviewProblemRedirection=true&search=meeting&leftPanelTabValue=PROBLEM)

You are given the schedule of `N` meetings with their start time `Start[i]` and end time `End[i]`.

You have only 1 meeting room. So, you need to return the maximum number of meetings you can organize.

## Intiution

Goal? 
- Schedule the maximum number of non-overlapping meetings.
- Two meetings overlap if one starts before the other ends.

Idea?
- Always choose the meeting that ends earliest. Reason: It frees the room sooner → allows more meetings later.
- If two meetings end at the same time, pick the one that starts earlier (tie-breaker).

## Greedy Approach

- Combine start and end into intervals.
- Sort by end time (primary), and start time (secondary).
- Iterate:
  - If the current meeting starts after the last chosen meeting ends, select it.
  - Update lastIdx to current meeting’s end.
  
```cpp
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    vector<vector<int>> intervals;
    for(int i=0;i<start.size();i++){
        intervals.push_back({start[i], end[i]});
    }

    sort(intervals.begin(), intervals.end(), 
        [](const vector<int> &a, const vector<int> &b){
            if(a[1]==b[1])
                return a[0] < b[0];
            return a[1]<b[1];
    });

    int lastIdx = -1, countNonOverlappingIntervals=0;
    for(int i=0;i<intervals.size();i++)
    {
        if(intervals[i][0] > lastIdx)
        {
            countNonOverlappingIntervals++;
            lastIdx = intervals[i][1];
        }
    }
    return countNonOverlappingIntervals;
}
```

> Time Complexity: `O(N * logN)`
>
> Space Complexity: `O(N)`