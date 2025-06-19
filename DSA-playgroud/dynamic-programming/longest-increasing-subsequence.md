# Longest Increasing Subsequence

Practice [Link](https://leetcode.com/problems/longest-increasing-subsequence/description/)

Given an integer array nums, return the length of the longest strictly increasing
subsequence.

## Brute Force

- Create all the subsequences
- filter the increasing subsequences
- pick the longest subsequence

> O(2^n) -> TLE (Overlapping subproblems)


## DP Approach

Intiution: 
- For every element find the lis ending with this element.
- For each element
  - Check for all elements smaller than it.
  - Take max of existing lis and lis of smaller element + 1 -> ```max(lis[i], lis[j]+1)```


```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, INT_MIN);
        lis[0]=1;
        
        for(int i=1;i<n;i++)
        {
            lis[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    lis[i] = max(lis[i], lis[j]+1);
            }
                
        }
        return *max_element(lis.begin(), lis.end());
    }
};
```
> Time Complexity: O(n*n)
> 
> Space Compelexity: O(n)

## Binary Search Approach

Intiution: 

- The step of finding the smallest element in all ```j < i``` can be reduced from linear search to binary search.

tail[i] -> stores the minimum possible tail value for lis of length i+1

Can also use the lower_bound method in C++ 

```int ceilIdx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin()```



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