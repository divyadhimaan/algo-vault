# Number of Longest Increasing Subsequence

Practice [Link](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

Given an integer array `nums`, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

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
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector<int> lis(n, 1);
        vector<int> count(n, 1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]){
                    if(lis[j]+1 > lis[i]){
                        lis[i] = lis[j]+1;
                        count[i] = count[j];
                    }else if(lis[j]+1==lis[i]){
                        count[i] += count[j];
                    }
                }
            }
             maxi = max(maxi, lis[i]);   
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(lis[i]==maxi)
                cnt += count[i];
        }
        return cnt;
    }
};
```
> Time Complexity: O(n*n)
> 
> Space Compelexity: O(n)
