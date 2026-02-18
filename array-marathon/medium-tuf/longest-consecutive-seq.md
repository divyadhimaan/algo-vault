# Longest Consecutive Sequence in an Array

Given an array nums of n integers.

Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

Note: Can have repeating numbers

## Brute Force

- For every element, use linear search to find consecutive numbers
- 3 loops
  - for each element
  - to check consecutive element
  - for linear search
- TC: O(n^3) --> TLE

## Better Approach

- Sort the array and find consecutive
- Keep a note of lastSmaller, as repetition can be there

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());


        // use lastSmaller as same number can repeat
        int len = 1, maxLen = -1, lastSmaller=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i] - 1 == lastSmaller){
                len++;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller){
                len=1;
                lastSmaller = nums[i];
            } 
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};
```

> Time Complexity: `O(nlogn) + O(n)`
>
> Space Complexity: O(1)

## Optimal Approach

- Use set to track the elements
- Find start of the sequence and check consecutive element presence in set

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;

        unordered_set<int> st;
        int maxLen = 1;

        for(int num: nums){
            st.insert(num);
        }

        for(auto it: st){
            //check if this ele is the starting of the seq
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;

                //find for other consecutive elements
                while(st.find(x+1) != st.end()){
                    x++;
                    cnt++;
                }

                maxLen = max(maxLen, cnt);
            }
        }
        return maxLen;
    }
};
```

> Time Complexity: `O(n)`
>
> Space Complexity: O(n)