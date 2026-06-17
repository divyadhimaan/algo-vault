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
> Time Complexity: O(n log n) — sorting 2n events costs O(n log n), single sweep is O(n)
>
> Space Complexity: O(n) — 2n events stored

---

## Min Heap (Priority Queue)

Push all events as `(time, char)` pairs into a min heap. The heap naturally processes events in time order, and since `'e' < 's'` in ASCII, end events at the same timestamp are popped before start events — correctly freeing a room before allocating a new one.

```cpp
typedef pair<int,char> pic;

class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        priority_queue<pic, vector<pic>, greater<pic>> pq;

        int n = start.size();
        for (int i = 0; i < n; i++) {
            pq.push({start[i], 's'});
            pq.push({end[i], 'e'});
        }

        int maxRooms = INT_MIN, currRooms = 0;
        while (!pq.empty()) {
            auto [time, event] = pq.top();
            pq.pop();

            if (event == 's') currRooms++;
            else              currRooms--;

            maxRooms = max(maxRooms, currRooms);
        }
        return maxRooms;
    }
};
```

> Time Complexity: O(n log n) — 2n pushes and 2n pops on a heap of size 2n, each costing O(log n)
>
> Space Complexity: O(n) — 2n elements in the heap

---

## Two Sorted Arrays (Two Pointers)

Separate start and end times into two sorted arrays. Use two pointers `i` (starts) and `j` (ends) to simulate the sweep without building event objects. If the next start is before the earliest end, a new room is needed; otherwise a room is freed and reused.

```cpp
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> starts(n), ends(n);

        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
            ends[i]   = intervals[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0, j = 0;
        for (int i = 0; i < n; i++) {
            if (starts[i] < ends[j]) {
                rooms++;           // new meeting starts before earliest end → need a room
            } else {
                j++;               // a meeting ended → reuse its room, don't increment
            }
        }
        return rooms;
    }
};
```

> Time Complexity: O(n log n) — two independent sorts, single O(n) pass
>
> Space Complexity: O(n) — two auxiliary arrays of size n

---

## Comparison

|                  | Sweep Line                        | Min Heap                         | Two Sorted Arrays               |
|------------------|-----------------------------------|----------------------------------|---------------------------------|
| **Time**         | O(n log n)                        | O(n log n)                       | O(n log n)                      |
| **Space**        | O(n)                              | O(n)                             | O(n)                            |
| **Tie-breaking** | Explicit comparator (`'e' < 's'`) | Implicit via ASCII (`'e' < 's'`) | Implicit (`<` keeps end ahead)  |
| **Style**        | Sort then sweep                   | Heap-driven sweep                | Two pointer                     |
| **Best for**     | Clearest intuition                | Natural heap framing             | Cleanest code, no extra objects |