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


> Time Complexity: `O(n^2)`
>
> Space Complexity: O(1)


## Optimal Approach

- Use hash map to optimally store the discovered sum.
- Intuition: If sum till i is same as sum till j (i < j) => sum of elements from i +1 to j is zero.
- We store the sum and its last occurrence while iterating, if we ever find same sum, we check the last occurrence to get the length.

```cpp
class Solution {
  public:
    int maxLen(vector<int>& arr) {
      int longest=0, sum=0;
      unordered_map<int,int> mp;
      
      for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        
        if(sum == 0){
          longest = i + 1;
        }
        else if(mp.find(sum) != mp.end()){
          longest = max(longest, i - mp[sum]);
        } else{
          mp[sum] = i;
        }
      }
      return longest;
    }
};
```

> Time Complexity: `O(n)`
>
> Space Complexity: O(n)