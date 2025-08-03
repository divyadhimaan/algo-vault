# Meeting Rooms

Given an array of meeting time intervals consisting of start and end times [(s1,e1),(s2,e2),...] (si < ei), determine if a person could attend all meetings.


```cpp
#include<iostream>
using namespace std;

unordered_map<int, string> intToBoolean = {
    {0, "False"},
    {1, "True"},
};

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

int main()
{

    // test 1:
    vector<vector<int>> intervals = {
        {1,30}, {5,10}, {15,20}
    };

    cout<<"Test case 1: "<<intToBoolean[canAttendMeetings(intervals)]<<endl;

    // test 2:
    vector<vector<int>> intervals2 = {
        {5,8}, {9,15}
    };
    cout<<"Test case 2: "<<intToBoolean[canAttendMeetings(intervals2)]<<endl;
    return 0;
}
```

> Time Complexity: `O(N * logN)`
>
> Space Complexity: `O(N)`