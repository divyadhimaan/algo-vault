#  Meeting Rooms III

Practice [here](https://leetcode.com/problems/meeting-rooms-iii/description/)

You are given an integer `n`. There are n rooms numbered from `0 to n - 1`.

You are given a 2D integer array `meetings` where `meetings[i] = [starti, endi]` means that a meeting will be held during the half-closed time interval `[starti, endi)`. All the values of `starti` are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval `[a, b)` is the interval between `a` and `b` including `a` and not including `b`.


## Intiution

You manage n meeting rooms, and there’s one locker that stores all room keys.
Each key in the locker has a tag:
```(tag) = (time when room is next free, room number) ```
The locker is sorted so the earliest free room key is always on top — and if there’s a tie, the smaller room number’s key is on top.


How the day plays out:
1. At the start:
   - Put all keys in the locker with (first meeting’s start time, room number) — meaning they’re free at that time.
2. For each meeting:
   - Step 1: Check the locker’s top key.
     - If its free time is before the meeting’s start, update its tag to say it’s free exactly at the meeting’s start, and put it back.
     - Keep doing this until no more keys qualify.
     (This ensures that among all free rooms, the smallest-numbered one rises to the top.)
   - Step 2: Take the top key from the locker — that’s the assigned room.
   If the room was still busy, this meeting starts late when it becomes free.
   - Step 3: Update the tag’s free time = current free time + meeting duration and toss it back in the locker.
     - Increment that room’s occupancy count.
3. After all meetings:
   - The most-used room is the one whose key was taken the most.

## Priority Queue based solution


```cpp
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> occupancy(101, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        for(int i=0;i<n;i++)
            pq.push({meetings[0][0], i});


        for(int i=0;i<meetings.size();i++)
        {
            //to ensure room with lowest number is assigned first
            while(pq.top().first < meetings[i][0])
            {
                pq.push({meetings[i][0], pq.top().second});
                pq.pop();
            }

            pair<long long, int> curr = pq.top();
            pq.pop();
            long long time = curr.first;
            int room = curr.second;
            pq.push({time + (meetings[i][1] - meetings[i][0]), room});
            occupancy[room]++;
        }

        return max_element(occupancy.begin(), occupancy.end()) - occupancy.begin();
    }
};
```

> Time Complexity: 
> 1. Sorting meetings → O(m log m)
>    - m = meetings.size()
> 2. Processing each meeting:
>     - Each meeting causes at most 1 pop + 1 push in the priority queue → O(log n) per operation.
>     - The while loop in total still pops/pushes at most m times overall, so it’s amortized into the same bound.
> 
> Overall: `O(mlogm+mlogn)`
Since n ≤ m in worst case,
`O(mlogm)`

> Space Complexity: 
> 1. Priority queue: stores at most n elements → O(n)
> 2. Occupancy array: O(n)
> Overall: `O(n)`