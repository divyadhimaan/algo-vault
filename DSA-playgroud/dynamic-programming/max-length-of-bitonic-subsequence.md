# Maximum Length of Bitonic Subsequence

Practice [Link](https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1)


Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. Return the maximum length of bitonic subsequence.
 
Note : `A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence`


## DP APPROACH

Intiution - 
Now with these two separate lengths of LIS, we can calculate the length of the longest bitonic subsequence for each index i. Here index i is acting as the pivot point of the points. Therefore the length of the longest bitonic subsequence at pivot [ i ] will be dp1[i] + dp2[i] -1.


```cpp
class Solution {
  public:
  int liscall(int n, vector<int> nums, vector<int> &lis)
	{
        lis[0] = 1;
        for(int i=1;i<n;i++)
        {
            lis[i]= 1;
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

	}
	int ldscall(int n, vector<int> nums, vector<int> &lds)
	{
        lds[n-1] = 1;
        for(int i=n-2;i>=0;i--)
        {
            lds[i]= 1;
            for(int j=n-1;j>i;j--)
            {
                if(nums[i] > nums[j])
                {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

	}
    int LongestBitonicSequence(int n, vector<int> &arr) {
        
        
        vector<int> lis(arr.size());
	    vector<int> lds(arr.size());
	    
	    liscall(n,arr,lis);
	    ldscall(n,arr, lds);
	    
	    int maxLength = 0;
	    for(int i=0;i<arr.size();i++)
	    {
            // Check if both LIS and LDS are valid 
            // for the current index
	        if(lis[i]> 1 && lds[i]>1)
	            maxLength = max(maxLength, lis[i] + lds[i] - 1);
	    }
	    return maxLength < 3 ? 0: maxLength;
    }
    
};
```