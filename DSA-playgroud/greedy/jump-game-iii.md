#  Jump Game III

Given an array of non-negative integers `arr`, you are initially positioned at `start` index of the array. When you are at index `i`, you can jump to `i + arr[i]` or `i - arr[i]`, check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.


## Implementation
```cpp
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==0)
            return true;

        queue<int> q;
        q.push(start);

        while(!q.empty())
        {
            int currIdx = q.front();
            q.pop();

            if(arr[currIdx]==0)
                return true;

            if(arr[currIdx]<0)
                continue;

            if(currIdx+arr[currIdx] < arr.size())
                q.push(currIdx+arr[currIdx]);

            if(currIdx-arr[currIdx]>=0)
                q.push(currIdx-arr[currIdx]);

            arr[currIdx] *= -1;

        }
        return false;
    }
};
```

> Time Complexity: O(n), Each index is visited at most once because you mark it by making arr[currIdx] negative.
>
> Space Complexity: O(n)