# Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times `[[s1,e1],[s2,e2],...] (si < ei)`, find the minimum number of conference rooms required.

> (0,8),(8,10) is not conflict at 8

> Test Case 1
> - Input: intervals = [(0,40),(5,10),(15,20)]
> 
> - Output: 2

> Test Case 2
> - Input: intervals = [(4,9)]
> 
> - Output: 1



## Intiution
- Think of each meeting as an event on a timeline:
  - Start → needs a room
  - End → frees a room
- Convert all intervals into events:
    ```
    (start_time, 's')
    (end_time, 'e')
    ```
- Sort events by time, and if times are equal, end comes before start
  - ensures a room is freed before a new meeting starts at the same time.
- Sweep through events:
  - When you see 's', increment room count.
  - When you see 'e', decrement room count.
  - Track the maximum rooms used simultaneously → this is the minimum required rooms.

## Sweep line algorithm (or timeline events approach).

```cpp
int minMeetingRooms(vector<vector<int>> &intervals)
{
    vector<pair<int, char>> events;
    for(auto &interval : intervals)
    {
        events.push_back({interval[0], 's'});
        events.push_back({interval[1], 'e'});
    }

    sort(events.begin(), events.end(),[](auto &a, auto &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });


    int rooms=0, maxRooms=0;
    for(size_t i=0;i<events.size();i++)
    {
        if(events[i].second=='s')
            rooms++;
        else
            rooms--;
        maxRooms = max(maxRooms, rooms);
    }
    return maxRooms;

}
```
> Time Complexity: O(n logn)
>
> Space Complexity: O (2*n)