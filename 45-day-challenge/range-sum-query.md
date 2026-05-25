# Range Sum Query

Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

## Prefix Sum

- instead of calculating sum again and again
- preprocess the prefix sum
- sum of range = prefix[right+1] - prefix[left]

```cpp
class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n+1, 0);

        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};



/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```