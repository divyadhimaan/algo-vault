# Check if array is sorted

Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.

```cpp
class Solution{	
	public:
		bool isSorted(vector<int>& nums){
			for(int i=1;i<nums.size();i++){
				if(nums[i-1] > nums[i])
					return false;
			}
			return true;
		}
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)