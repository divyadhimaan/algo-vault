# Implement Lower Bound

Practice [Link](https://www.geeksforgeeks.org/problems/implement-lower-bound/1)

Given a sorted array `arr[]` and a number `target`, the task is to find the lower bound of the `target` in this given array. The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.

Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 


```cpp
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int s = 0, e = arr.size()-1;
        int res=arr.size();
        
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(arr[mid]>=target){
                res = mid;
                e =mid-1;
            }else
                s = mid+1;
        }
        return res;
    }
};
```


> Time Complexity: O(logn)
>
> Space Complexity: O(1)