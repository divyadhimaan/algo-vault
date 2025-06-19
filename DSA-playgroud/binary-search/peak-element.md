# Find Peak Element

Practice [Link](https://leetcode.com/problems/find-peak-element/description/)


A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that `nums[-1] = nums[n] = -∞`. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in `O(log n)` time.


## Intiution

- We use Binary Search to reach the peak. 
- Handle the edge elements being teh peak.
- This code will also handle the multiple peaks -> it will either be on the left/right.
  
- left < mid > right -> peak
- left < mid -> peak on right
- right > mid -> peak on left // this also needs to handle the case when the mid is the valley element, so it can either go to left or right.


```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        

        if(n==1)
            return 0;

        if(nums[0] > nums[1])
            return 0;
        if(nums[n-1]>nums[n-2])
            return n-1;


        int s = 1, e = n-2;

        int res = 0;
        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                res = mid;
                break;
            }
            else if(nums[mid-1]<nums[mid])//increasing slope
                s=mid+1;
            else //decreasing slope
                e = mid-1;
        }
        return res;
    }
};

```

> Time Complexity: O(logn)
>
> Space Complexity: O(1)