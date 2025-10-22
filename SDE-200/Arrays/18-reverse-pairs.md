# Reverse pairs


## Brute Force Approach

```cpp
class Solution {
public:
    int reversePairs(vector<int>& nums) {

        int counter=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i] > 2*nums[j]){
                    counter++;
                }
            }
        }
        return counter;
    }
};
```

## Better Approach