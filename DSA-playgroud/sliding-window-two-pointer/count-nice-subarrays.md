# Count Number of Nice Subarrays

Practice [Link](https://leetcode.com/problems/count-number-of-nice-subarrays/)


Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.


## Approach 1

- If we consider `even` number as `0` and `odd` as `1`
- This problem can be considered same as binary array with sum as k

> Best for binary (0/1) arrays
```cpp
class Solution {
public:

    int helper(vector<int> &nums, int k)
    {
        if(k<0)
            return 0;

        int l =0,r=0;

        int currSum=0,cnt=0;
        while(r<nums.size())
        {
            currSum += nums[r];
            while(currSum > k && l<=r)
            {
                currSum -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }

    int findSubarraysWithSumInBinaryArray(vector<int>& nums, int k)
    {
        return helper(nums, k) - helper(nums, k-1); 
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        
        for(int i=0;i<nums.size();i++)
            if(nums[i]%2==0)
                nums[i] = 0;
            else
                nums[i] = 1;

        return findSubarraysWithSumInBinaryArray(nums, k); 
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)

## Approach 2 - PrefixSum + Hashmap


```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount;
        prefixCount[0]=1;
        int sum=0,cnt=0;

        for(int i=0;i<nums.size();i++)
        {
            nums[i] = nums[i]%2;
            sum += nums[i];
            if(prefixCount.count(sum-k))
                cnt += prefixCount[sum-k];
            prefixCount[sum]++;
        }
        return cnt;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)