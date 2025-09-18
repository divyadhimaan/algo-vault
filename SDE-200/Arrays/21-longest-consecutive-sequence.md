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

## Union Find 

- The problem asks for the longest consecutive sequence.
- Normally, we solve this with a HashSet in O(n). But Union-Find also works:
  - Treat each number as a node.
  - Union two numbers if they are consecutive (x and x+1).
- At the end, the largest connected component size = longest consecutive sequence.


### approach

1. Remove duplicates from nums (since multiple same numbers don’t add length).
2. Map each number → index (map<int,int>).
3. Initialize Union-Find with n nodes.
4. For each number x, if x+1 exists, union their indices.
5. Keep track of component sizes.
6. Return maximum size across all components.

```cpp
class UnionFind{
public:
    vector<int> par;
    vector<int> size;

    UnionFind(int n)
    {
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
            par[i]=i;
    }

    int find(int x)
    {
        if(par[x]==x)
            return x;
        
        return par[x] = find(par[x]);
    }

    void Union(int x, int y)
    {
        int xRep = find(x);
        int yRep = find(y);

        if(xRep == yRep)
            return;

        if(size[xRep] < size[yRep])
            swap(xRep, yRep);

        par[yRep] = xRep;
        size[xRep] += size[yRep];
    }

    int getSize(int x)
    {
        return size[find(x)];
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;

        int idx=0;
        for(int num: nums)
        {
            if(map.count(num))
                continue;
            map[num] = idx++;
        }


        UnionFind uf(idx);

        for(auto &[num, i]: map){
            if(map.count(num+1))
                uf.Union(i, map[num+1]);
        }

        int longest=0;
        for(int i=0;i<idx;i++){
            longest = max(longest, uf.getSize(i));
        }
        return longest;
    }
};
```

> Time Complexity: O(n)
> - Insert into hashmap: O(n)
> - Union-Find ops (amortized): O(α(n)) ≈ O(1).
> 
> Space: O(n)