# Print Longest Increasing Subsequence

Practice [Link](https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence)

Given an integer n and an array of integers arr, return the Longest Increasing Subsequence which is Index-wise lexicographically smallest.
Note - A subsequence S1 is Index-wise lexicographically smaller than a subsequence S2 if in the first position where S1 and S2 differ, subsequence S1 has an element that appears earlier in the array  arr than the corresponding element in S2.
LIS  of a given sequence is defined as that longest possible subsequence all of whose elements are in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and the LIS is {10, 22, 33, 50, 60, 80}. 

## DP Approach

Intiution: 
- For every element find the lis ending with this element.
- For each element
  - Check for all elements smaller than it.
  - Take max of existing lis and lis of smaller element + 1 -> ```max(lis[i], lis[j]+1)```


```cpp
void printLis(vector<int> &arr, vector<int> &hash, int idx, vector<int>& result)
    {
        result.push_back(arr[idx]);
        while(hash[idx] != idx)
        {
            idx = hash[idx];
            result.push_back(arr[idx]);
        }
        reverse(result.begin(), result.end());
    }
  
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> lis(n);
        vector<int> hash(n);
        lis[0] = 1;
        
        for(int i=1;i<n;i++)
        {
            hash[i] = i;
            lis[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(arr[i] > arr[j] && lis[i] < 1 + lis[j])
                {
                    lis[i]  = 1+lis[j];
                    hash[i] = j;
                }
            }
        }
        
        int lisIdx = max_element(lis.begin(), lis.end()) - lis.begin();
        
        vector<int> result;
        printLis(arr, hash, lisIdx, result);
        
        return result;
    }
```
> Time Complexity: O(n*n)
> 
> Space Compelexity: O(n)
