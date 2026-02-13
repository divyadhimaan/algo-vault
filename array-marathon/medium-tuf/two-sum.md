# Two Sum

## Brute Force

- Check all pairs

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target)
                    return vector<int>{i,j};
            }
        }
        return {-1,-1};
    }
};
```

> Time Complexity: O(n^2) --> TLE
>
> Space Complexity: O(1)

## Better Solution

- Use hashmap for storing previously visited values and there indices

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueIdxMap;

        for(int i=0;i<nums.size();i++){
            if(valueIdxMap.find(target - nums[i]) != valueIdxMap.end()){
                return vector<int> {valueIdxMap[target-nums[i]], i};
            }

            valueIdxMap[nums[i]] = i;
        }
        return {-1,-1};
    }
};
```

> Time Complexity: O(n) 
>
> Space Complexity: O(n)

## Optimal Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int low = 0, high = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(valueIdxMap.find(target - nums[i]) != valueIdxMap.end()){
                return vector<int> {valueIdxMap[target-nums[i]], i};
            }

            valueIdxMap[nums[i]] = i;
        }
        return {-1,-1};
    }
};
```

