# Longest Consecutive Sequence

Practice [Link](https://leetcode.com/problems/longest-consecutive-sequence/description/)

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



## sorting Based

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int cnt =0, longest=0;
        int lastSmaller = INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(nums[i]-1 == lastSmaller){
                cnt++;
                lastSmaller = nums[i];
            }else if(nums[i] != lastSmaller){
                cnt=1;
                lastSmaller = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};
```

> Time Complexity: O(nlogn)
>
> Space Complexity: O(1)

## Better Approach


### Intiution
The problem asks for the length of the longest consecutive sequence in an unsorted array. First thought was that sorting the array could help, but that would take O(n log n) time, and the goal is to do it in linear time.
Using a hash set allows for constant-time lookups, which can help us find sequences efficiently.

Approach:
- We insert all numbers from the input array into an unordered set for O(1) average time lookups.
- We iterate through the set. For each number, we check if it is the start of a sequence (i.e., num - 1 is not in the set).
- If it is the start, we incrementally check for the next elements in the sequence using a while loop (num + 1, num + 2, etc.).
- We track the length of each sequence and update the maximum length found so far.

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int longest=0;
        for(int num: s)
        {
            if(!s.count(num-1))
            {
                int curr = num;
                int streak = 1;

                while(s.count(curr+1))
                {
                    curr++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)