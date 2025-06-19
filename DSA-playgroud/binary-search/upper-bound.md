# Upper bound

Practice [Link](https://www.geeksforgeeks.org/problems/implement-upper-bound/1)

Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.

The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.

Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.


```cpp
int upperBound(vector<int>& arr, int target) {
        int s = 0, e = arr.size()-1;
        int res=arr.size();
        
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(arr[mid]>target){
                e =mid-1;
            }else{
                s = mid+1;
            }
        }
        return s;
    }
```

> Time Complexity: O(logn)
>
> Space Complexity: O(1)