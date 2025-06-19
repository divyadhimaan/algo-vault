# Next Greater Element II

Practice [Link](https://leetcode.com/problems/next-greater-element-ii/description/)


Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.


## Intiution
-  Everything exactly same as [next greater element I](./next-greater-element.md), except now we have a circular array
-  We will hypothetically assume an array of `2*n` size and follow same steps.
-  We only update the resultant array if `current idx < n`


## Solution - Monotonic Stack

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> ans(n,-1);

        for(int i=2*n-1;i>=0;i--)
        {
            while(!stk.empty() && stk.top() <= nums[i%n])
                stk.pop();

            if(!stk.empty() && i<n)
                ans[i] = stk.top();

            stk.push(nums[i%n]);
        }
        return ans;
    }
};
```

> Time Complexity: O(2n)
> 
> Space Complexity: O(n)