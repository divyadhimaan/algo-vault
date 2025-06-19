# Find Kth Rotation

Practice [Link](https://www.geeksforgeeks.org/problems/rotation4723/1)

Given an increasing sorted rotated array `arr` of distinct integers. The array is right-rotated `k` times. Find the value of `k`.
Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]


## Implementation
- An array's no of rotations is nothing but min element's index.

```cpp
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();

        int s = 0, e =n-1;
        int ans = INT_MAX;
        int idx=-1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(arr[s] <= arr[mid]) //first half sorted
            {
                if(arr[s]<ans){
                    ans = arr[s];
                    idx=s;
                }
                s = mid+1;
            }
            else//seconf half sorted
            {
                if(arr[mid]<ans){
                    ans = arr[mid];
                    idx=mid;
                }
                e = mid-1;
            }
        }
        return idx;
    }
};
```

> Time Complexity: O(logn)
>
> Space Complexity: O(1)