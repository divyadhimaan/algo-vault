# Number of occurrences in Sorted Array

Practice [Link](https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1)

Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 


```cpp
class Solution {
  public:
  
    int BinarySearch(vector<int> &nums, int s, int e, int target, bool searchLeft)
    {
        int res = -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                res = mid;
                if(searchLeft)
                    e = mid-1;
                else
                    s = mid+1;
            }else if(nums[mid]<target)
                s= mid+1;
            else
                e = mid-1;
        }
        return res;
    }
  
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        
        int l = BinarySearch(arr, 0, n-1, target, true);
        int r = BinarySearch(arr, 0, n-1, target, false);

        
        if(l==-1 || r==-1)
            return 0;
        return r-l+1;
    }
};
```


> Time Complexity: O(logn)
>
> Space Complexity: O(1)