# Largest Subarray with Sum 0

You are given an integer array arr of size n which contains both positive and negative integers. Your task is to find the length of the longest contiguous subarray with sum equal to 0.

Return the length of such a subarray. If no such subarray exists, return 0.

## Brute Force
- Find all subarrays and check the sum

```cpp
class Solution {
  public:
    int maxLen(vector<int>& arr) {
      int longest=0;
      
      for(int i = 0; i < arr.size(); i++){
        int sum = 0;
        for(int j = i; j < arr.size(); j++){
          sum += arr[j];
          if(sum == 0){
            longest = max(longest, j-i+1);
          }
        }
      }
      return longest;
    }
};
```