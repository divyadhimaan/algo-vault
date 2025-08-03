#include<bits/stdc++.h>
using namespace std;

bool canAttendMeetings(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    for(int i=1;i<intervals.begin();i++)
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

    cout<<"Test case 1: "<<canAttendMeetings(intervals);

    // test 2:
    vector<vector<int>> intervals2 = {
        {5,8}, {9,15}
    };
    cout<<"Test case 2: "<<canAttendMeetings(intervals2);
    return 0;
}