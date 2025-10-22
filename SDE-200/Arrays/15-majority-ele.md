# Majority Element (n/2 times)

## Brute Force

For every element, count the occurrences and find majority elements.

## Better Solution

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> hashMap;
        for(int num: nums){
            hashMap[num]++;
        }

        for(auto x: hashMap){
            if(x.second > n/2){
                return x.first;
            }
        }
        return -1;
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
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majCount=0, majEle=-1;

        for(int i=0; i<n; i++){
            if(majCount==0){
                majCount = 1;
                majEle = nums[i];
            }else if(majEle == nums[i]){
                majCount++;
            }else{
                majCount--;
            }
        }
        return majEle;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)