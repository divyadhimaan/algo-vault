# Longest Increasing Subsequence

Practice [Link](https://leetcode.com/problems/longest-increasing-subsequence/description/)

Given an integer array nums, return the length of the longest strictly increasing
subsequence.


## Brute Force

- Create all the subsequences
- filter the increasing subsequences
- pick the longest subsequence

```cpp
class Solution {
public:
    int LISUtilRecur(vector<int> nums, int idx, int prevIdx){
        if(idx == nums.size()){
            return 0;
        }

        int notTake = LISUtilRecur(nums, idx+1, prevIdx);

        int take = 0;

        if(prevIdx == -1 || nums[idx] > nums[prevIdx])
            take = 1 + LISUtilRecur(nums, idx+1, idx);

        return max(take, notTake);
    }

    int LIS(vector<int>& nums) {
      return LISUtilRecur(nums, 0, -1);
    }    
};
```

> O(2^n) -> TLE (Overlapping subproblems)

## Memoized Approach

```cpp
class Solution {
public:
    int LISUtilRecur(vector<int> nums, int idx, int prevIdx, vector<vector<int>> &memo){
        if(idx == nums.size()){
            return 0;
        }

        if(memo[idx][prevIdx + 1] != -1)
            return memo[idx][prevIdx+1];

        int notTake = LISUtilRecur(nums, idx+1, prevIdx, memo);

        int take = 0;

        if(prevIdx == -1 || nums[idx] > nums[prevIdx])
            take = 1 + LISUtilRecur(nums, idx+1, idx, memo);

        return memo[idx][prevIdx+1] = max(take, notTake);
    }

    int LIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n , vector<int>(n+1, -1));
      return LISUtilRecur(nums, 0, -1, memo);
    }    
};
```
> O(n^2) -> TLE (Overlapping subproblems)

## DP Approach

Intuition: 
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
> Time Complexity: O(n*n) --> TLE
> 
> Space Complexity: O(n)

## Binary Search Approach

Intuition: 

- The step of finding the smallest element in all ```j < i``` can be reduced from linear search to binary search.

- tail[i] -> stores the minimum possible tail value for lis of length i+1


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


## FOLLOW UP: To return the LIS itself

### DP approach
```cpp
#include <vector>
using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> array) {
  int n = array.size();
  vector<int> parent(n, -1);
  vector<int> lis(n, 1);

  for(int i = 1; i < n; i++){

    for(int j = 0; j < i; j++){
      if(array[j] < array[i] && lis[j] + 1 > lis[i]){
        lis[i] = lis[j]+1;
        parent[i] = j;
      }
    }
  }

  int lastIdx = max_element(lis.begin(), lis.end()) - lis.begin();

  vector<int> result;
  while(lastIdx != -1){
    result.push_back(array[lastIdx]);
    lastIdx = parent[lastIdx];
  }

  reverse(result.begin(), result.end());
  

  return result;
}
```

## Binary Search Approach

```cpp
#include <vector>
using namespace std;

int getCeilIdx(vector<int> array, vector<int> &tailIdx, int low, int high, int target){
  while(low < high){
    int mid = (low + high) / 2;
    if(array[tailIdx[mid]] >= target)
      high = mid;
    else
      low = mid + 1;
  }
  return high;
}

  

vector<int> longestIncreasingSubsequence(vector<int> array) {
  int n = array.size();
  vector<int> prevIdx(n, -1);
  vector<int> tailIdx(n);
  tailIdx[0] = 0;
  int len = 1;

  for(int idx = 1; idx < n; idx++){
    if(array[tailIdx[len-1]] < array[idx]){
      prevIdx[idx] = tailIdx[len-1];
      tailIdx[len++] = idx;
    }
    else{
      int low = 0, high = len-1;
      while(low < high){
        int mid = (low + high) / 2;
        if(array[tailIdx[mid]] >= array[idx])
          high = mid;
        else
          low = mid + 1;
      }
      int ceilIdx = high;

      if(low > 0)
          prevIdx[idx] = tailIdx[low-1];

      tailIdx[ceilIdx] = idx;
    }
  }

  vector<int> lis;
  int idx = tailIdx[len-1];

  while(idx != -1){
    lis.push_back(array[idx]);
    idx = prevIdx[idx];
  }

  reverse(lis.begin(), lis.end());

  
  return lis;
}

```