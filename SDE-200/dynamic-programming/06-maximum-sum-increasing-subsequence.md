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


> NOTE: Cannot use LIS based binary search approach as sum dependency breaks monotonicity


## Follow Up: return the items contributing to MSIS

```cpp
#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> arr) {
  int n = arr.size();
  vector<int> msis(n);
  vector<int> parent(n, -1);

  msis[0] = arr[0];

  for(int i = 1; i < n; i++){
      msis[i] = arr[i];
      for(int j = 0; j < i; j++){
          if(arr[j] < arr[i] && msis[j] + arr[i] > msis[i]){
              msis[i] = msis[j] + arr[i];
              parent[i] = j;
          }
      }
  }
  int maxiIdx = max_element(msis.begin(), msis.end()) - msis.begin();
  int maxi =  msis[maxiIdx];

  vector<int> seq;

  while(maxiIdx != -1){
    seq.push_back(arr[maxiIdx]);
    maxiIdx = parent[maxiIdx];
  }

  reverse(seq.begin(), seq.end());
  
  return {
    {maxi},  // Sum of sequence.
    seq,   // Elements of the sequence.
  };
}

```

> Time Complexity: O(n*n) + O(n)
>
> Space Compelexity: O(n) + O(n)