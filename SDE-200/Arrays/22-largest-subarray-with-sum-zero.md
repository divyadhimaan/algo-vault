# Largest subarray with 0 sum

Practice [Link](https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1)

Given an array arr containing both positive and negative integers, the task is to compute the length of the largest subarray that has a sum of 0.

```cpp
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        int maxLen=0;
        
        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=i;j<n;j++)
            {
                sum += arr[j];
                
                if(sum==0)
                    maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};
```

> Time Complexity: O(n^2)
>
> Space Complexity: O(1)

```cpp
class Solution {
  public:
    int maxLen(vector<int>& arr) {
       unordered_map<int,int> mp;
       int sum = 0, maxLen=0;
       
       for(int i=0;i<arr.size();i++)
       {
           sum += arr[i];
           
            if(sum==0)
                maxLen = i+1;
            else{
                if(mp.find(sum) != mp.end())
                    maxLen = max(maxLen, i - mp[sum]);
                else
                    mp[sum] = i;
            }
            
       }
       return maxLen;
    }
    
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)