# Jump Game

Practice [here](https://leetcode.com/problems/jump-game/description/)


You are given an integer array `nums`. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return `true` if you can reach the last index, or `false` otherwise.


## Recursion Approach

```cpp
class Solution {
public:
    bool canJumpUtil(vector<int>& nums, int idx)
    {
        if(idx>=nums.size())
            return false;
        if(idx==nums.size()-1)
            return true;

        for(int i=1;i<=nums[idx];i++){
            if(canJumpUtil(nums, idx+i))
                return true;   
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        return canJumpUtil(nums, 0);
    }
};
```

> Time Complexity: O(2<sup>n</sup>) -> TLE
>
> Space Complexity: O(n)

## Greedy Approach

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>maxReach)
                return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
```


> Time Complexity: O(n)
>
> Space Complexity: O(1)
