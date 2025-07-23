# Contains Duplicate

Given an integer `array`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.


## Brute Force

- For every element check if repeatition found.

> Time Complexity: O(n<sup>2</sup>)
>
> Space Complexity: O(1)

## Better Approach: Sorting

- Sort the elements
- Compare consecutive elements

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
};
```

> Time Complexity: O(nlogn)
>
> Space Complexity: O(1)

## Better Approach : HashSet

- Use set to check repetition
  
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.count(nums[i]))
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
```

> Time Complexity: O(n) (Refer [Time complexity](./../../time-compelxities-of-common-ds.md#unordered_set-stl) for unordered_set)
>
> Space Complexity: O(n)

