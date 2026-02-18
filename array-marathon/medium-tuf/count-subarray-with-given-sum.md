# Count subarrays with given sum

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

## Brute Force

- Find all subarrays
- Count subarrays

> Time Complexity: `O(n^2)` --> TLE
>
> Space Complexity: O(1)

## Optimal Approach

### Intuition

- For any subarray: `sum(i…j) = prefix[j] − prefix[i−1]`
- We want: `prefix[j] − prefix[i−1] = k`
- Rearrange: `prefix[i−1] = prefix[j] − k`
- So the question becomes: How many previous prefix sums equal to currentPrefix - k exist?

### Working

- Use map to store the prefixSum and its occurrence
- while traversing, Check if the (k-prefixSum) has been discovered before, also keep note of how many times discovered

```cpp
class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
        
        int cnt = 0, prefixSum = 0; 
        unordered_map<int,int> prefixSumMap;

        prefixSumMap[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];

            cnt += prefixSumMap[prefixSum - k];

            prefixSumMap[prefixSum]++;
        }

        return cnt;
    }
};
```

> Time Complexity: `O(n)` 
>
> Space Complexity: O(n)