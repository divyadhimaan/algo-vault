# Longest Subarray of 1's After Deleting One Element

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

## Sliding Window 
- One zero is allowed in window, since we can delete it.
- As soon as you discover second zero, shift the zero

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        int zeroCount = 0;
        int maxLen = INT_MIN;

        for(int end = 0; end < n; end++){
            if(nums[end] == 0){
                zeroCount++;
            }

            while(zeroCount > 1){
                if(nums[start]==0)
                    zeroCount--;
                start++;
            }

            maxLen = max(maxLen, end-start);
        }
        if(maxLen == INT_MIN)
            return 0;
        return maxLen;
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(1)