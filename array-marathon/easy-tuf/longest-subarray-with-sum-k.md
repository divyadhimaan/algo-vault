# Longest subarray with sum K

Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

## Brute Force

```cpp
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int maxLen = -1;

        for(int i=0;i<nums.size();i++){
            int sum = k;
            for(int j=i;j<nums.size();j++){
                sum -= nums[j];
                if(sum==0)
                    maxLen = max(maxLen, j-i+1);
                
            }
        }
        return maxLen == -1 ? 0 : maxLen;
    }
};

```

> Time Complexity: O(n^2) --> TLE
>
> Space Complexity: O(1)


## Optimal (Only Positives)

- Use Sliding window 
```cpp
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int start = 0, end = 0;

        int longestLen = 0, sum=0;

        while(end < nums.size()){
            sum += nums[end];

            while(sum > k){
                sum -= nums[start];
                start++;
            }

            if(sum == k){
                longestLen = max(longestLen, end-start+1);
            }
        
            end++;
        }
        return longestLen;
    }
};

```

> Time Complexity: O(n)
>
> Space Complexity: O(1)


## Optimal Approach (Handling Positives + Negatives + Zeroes)

```cpp
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        map<int, int> preSumMap;

        int sum = 0, longestLen = 0;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];

            if(sum == k){
                longestLen = max(longestLen, i+1);
            }           

            if(preSumMap.find(sum-k) != preSumMap.end()){
                longestLen = max(longestLen, i - preSumMap[sum-k]);
            }
            if(preSumMap.find(sum) == preSumMap.end())
                preSumMap[sum] = i;
        }

        return longestLen;
    }
};

```

> Time Complexity: O(n)
>
> Space Complexity: O(n)