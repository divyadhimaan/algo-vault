#include<iostream>
using namespace std;


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

int main()
{

    // test 1:
    vector<vector<int>> intervals = {
        {1,30}, {5,10}, {15,20}
    };


    cout<<"Test case 1: "<<minMeetingRooms(intervals)<<endl;

    // test 2:
    vector<vector<int>> intervals2 = {
        {2,7}
    };
    cout<<"Test case 2: "<<minMeetingRooms(intervals2)<<endl;


    vector<vector<int>> intervals3 = {{1,2}, {2,3}, {3,4}};
    cout<<"Test case 3: "<<minMeetingRooms(intervals3)<<endl;


    vector<vector<int>> intervals4 = {{1,4}, {2,5}, {3,6}};
    cout<<"Test case 4: "<<minMeetingRooms(intervals4)<<endl;

    vector<vector<int>> intervals5 = {{1,3}, {1,2}, {1,4}};
    cout<<"Test case 5: "<<minMeetingRooms(intervals5)<<endl;

    return 0;
}