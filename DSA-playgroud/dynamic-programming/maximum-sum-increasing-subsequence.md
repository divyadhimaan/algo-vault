# Maximum Sum Increasing Subsequence

Practice [Link](https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1)

Given an array of positive integers arr. Find the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 




## DP Approach

```cpp
class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> msis(n);
        for(int i=0;i<n;i++)
        {
            msis[i] = arr[i];
            for(int j=0;j<i;j++)
            {
                if(arr[j] < arr[i])
                    msis[i] = max(msis[i], arr[i] + msis[j]);
            }
        }
        return *max_element(msis.begin(), msis.end());
    }
};
```
> Time Complexity: O(n*n)
> 
> Space Compelexity: O(n)

## Binary Search Approach


```cpp
class Solution {
public:

    int ceilIdx(vector<int> &tail, int l, int r, int x)
    {
        while(l < r)
        {
            int m = (l+r)/2;
            if(tail[m] >= x)
                r = m;
            else
                l = m+1;
        }
        return r;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tail(n);
        tail[0]=nums[0];
        int len = 1;

        for(int i=1;i<n;i++)
        {
            if(tail[len-1] < nums[i]){
                tail[len++] = nums[i];
            }
            else{
                int c = ceilIdx(tail, 0, len-1, nums[i]);
                tail[c] = nums[i];
            }
        }
        return len;
    }
};
```


> Time Complexity: O(n*log n)
>
> Space Complexity: O(n)