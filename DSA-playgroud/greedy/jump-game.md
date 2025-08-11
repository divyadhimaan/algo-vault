# Jump Game

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

> Time Complexity: O(2<sup>n</sup>)
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
