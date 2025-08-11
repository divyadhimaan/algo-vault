# Jump Game II

Practice [here](https://leetcode.com/problems/jump-game-ii/description/)

You are given a **0-indexed** array of integers `nums` of length `n`. You are initially positioned at index 0.

Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at index `i`, you can jump to any index `(i + j)` where:

`0 <= j <= nums[i]` and
`i + j < n`
Return the minimum number of jumps to reach index `n - 1`. The test cases are generated such that you can reach index n - 1.

## Recursive Approach

```cpp
class Solution {
public:
    int minJumps;
    void jumpsUtil(vector<int>& nums, int idx, int jumps)
    {
        if(idx>=nums.size())
            return;

        if(idx==nums.size()-1)
            minJumps = min(minJumps, jumps);

        for(int i=1;i<=nums[idx];i++){
            jumpsUtil(nums, idx+i, jumps+1);
        }
    }
    int jump(vector<int>& nums) {
        minJumps = INT_MAX;
        jumpsUtil(nums, 0, 0);
        return minJumps;
    }
};
```

> Time Complexity: O(2<sup>n</sup>) -> TLE
>
> Space Complexity: O(n)

## DP Approach

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumps(n, INT_MAX);
        jumps[0]=0;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]+j>=i)
                    jumps[i] = min(jumps[i], jumps[j]+1);
            }
        }
        return jumps[n-1];
    }
};
```

> Time Complexity: O(n<sup>2</sup>)
>
> Space Complexity: O(n)

## Greedy Approach
- You track the farthest index you can reach so far (`coverage`).
- You also keep track of the end of your current jump range (`lastIdx`).
- As you walk through the array:
  - Update `coverage` with the farthest point reachable from any index within the current range.
  - When you reach `lastIdx`, it means you’ve finished the current jump — so you increment jumps and set `lastIdx = coverage` to start a new jump range.
- If at any point coverage reaches or exceeds the last index, you can stop.

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;

        int coverage = 0, lastIdx=0, jumps=0;

        for(int i=0;i<n;i++)
        {
            coverage = max(coverage, i+nums[i]);

            if(i==lastIdx){
                lastIdx = coverage;
                jumps++;

                if(coverage >= n-1)
                    break;
            }
        }
        return jumps;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)