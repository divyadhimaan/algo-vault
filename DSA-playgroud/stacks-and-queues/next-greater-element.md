# Next Greater Element I

Practice [Link](https://leetcode.com/problems/next-greater-element-i/description/)


The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

## Intiution
-  We maintain a stack called monotonic stack (descreasing)
- Traverse the second array from the back and store the respected greater elements in map. 
- Finally, we map the first array elements in the map data structure and return them.


## Solution - Monotonic Stack

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        stack<int> stk;

        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!stk.empty() && stk.top()<=nums2[i])
                stk.pop();

            if(!stk.empty())
                mpp[nums2[i]] = stk.top();
            else
                mpp[nums2[i]] = -1;
            stk.push(nums2[i]);
        }

        vector<int> ans;
        for(int num: nums1)
        {
            ans.push_back(mpp[num]);
        }

        return ans;

    }
};
```

> Time Complexity: O(2n)
> 
> Space Complexity: O(n)