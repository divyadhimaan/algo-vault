# Leaders in an Array

Given an integer array nums, return a list of all the leaders in the array.

A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. 
The elements in the leader array must appear in the order they appear in the nums array.


## optimal Approach

```cpp
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[n-1];

        vector<int> ans;
        ans.push_back(maxi);

        for(int i=n-2;i>=0;i--){
            if(nums[i] > maxi){
                maxi = nums[i];
                ans.push_back(nums[i]);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

> Time Complexity: `O(n)`
>
> Space Complexity: O(1)

