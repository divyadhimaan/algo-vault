# Minimum Size Subarray Sum
Practice [Link](https://leetcode.com/problems/minimum-size-subarray-sum/description/)


## Brute Force
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int miniLength=INT_MAX;

        for(int i=0;i<n;i++)
        {
            int sum = 0;
            for(int j=i;j<n;j++)
            {
                sum += nums[j];
                if(sum >= target){
                    miniLength = min(miniLength, j-i+1);
                    break;
                }
            }
        }
        if(miniLength==INT_MAX)
            return 0;
            
        return miniLength;
    }
};
```

> Time Complexity: `O(n^2)`, --> TLE
>
> Space Complexity: `O(1)`, 

## Sliding Window

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i =0,j=0, minLength = INT_MAX, sum=0;

        while(i<n || j<n)
        {
            if(sum >= target)
                minLength = min(minLength, j-i);

            if(j<n && sum<target){
                sum += nums[j];
                j++;
            }else{
                sum -= nums[i];
                i++;
            }
        }

        if(sum>=target)
            minLength = min(minLength, j-i);
            
        if(minLength==INT_MAX)
            return 0;

        return minLength;
    }
};
```

> Time Complexity: `O(n)`,
>
> Space Complexity: `O(1)`, 