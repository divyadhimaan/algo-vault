# Meeting Rooms

Given an array of meeting time intervals consisting of start and end times [(s1,e1),(s2,e2),...] (si < ei), determine if a person could attend all meetings.


```cpp
bool canAttendMeetings(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    for(int i=1;i<intervals.size();i++)
    {
        if(intervals[i][0] < intervals[i-1][1])
            return false;
    }
    return true;
}
```

> Time Complexity: `O(N * logN)`
>
> Space Complexity: `O(N)`