# Subsets with sum k

Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Practice [Link](https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem)

## Recursive

```cpp
class Solution{
	public:
    int MOD = 1e9+7;
    int perfectSumUtil(vector<int>&arr, int K, int idx){
        
        if(K==0)
            return 1;
            
        if(idx<0){
            return 0;
        }
        

        int not_take = perfectSumUtil(arr, K, idx-1);
        int take = 0;
        if(arr[idx] <= K)
            take = perfectSumUtil(arr, K - arr[idx], idx-1);

        return take + not_take;
    }

	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        return perfectSumUtil(arr, K, n-1)%MOD;
	}
};
```
> Time Complexity - `O(2^n)` -> TLE

---

## Memoized

```cpp
class Solution{
	public:
    int MOD = 1e9 + 7;
    int perfectSumUtil(vector<int>&arr, int K, int idx, vector<vector<int>> &memo){
        
        if(K==0)
            return 1;

        if(idx<0)
            return 0;

        if(memo[idx][K] != -1)
            return memo[idx][K];

        long long not_take = perfectSumUtil(arr, K, idx-1, memo);
        long long take = 0;
        if(arr[idx] <= K)
            take = perfectSumUtil(arr, K - arr[idx], idx-1, memo);

        return memo[idx][K] = (take + not_take)%MOD;
    }

	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        vector<vector<int>> memo(n, vector<int>(K+1, -1)); 
        return perfectSumUtil(arr, K, n-1, memo);
	}
};
```
> Time Complexity - `O(n*k)`
>
> Space Complexity - `O(n*k ) + O(n)`

---

## Tabulation

```cpp
class Solution{
	public:
    int MOD = 1e9 + 7;

	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();

        // dp[i][j] -> number of subsets using elements from 0…i that sum to j
        vector<vector<int>> dp(n, vector<int>(K+1, 0));

        for(int i=0;i<n;i++){
            dp[i][0] = 1; //A sum of 0 is always possible
        }

        if(arr[0] <= K)
            dp[0][arr[0]] = 1; //one subset exists

        for(int i=1;i<n;i++){
            for(int j=1;j<=K;j++){
                long long not_take = dp[i-1][j];

                long long take = 0;
                if(arr[i] <= j)
                    take = dp[i-1][j-arr[i]];

                dp[i][j] = (take+not_take)%MOD;
            }
        }

        return dp[n-1][K];
	}
};
```


> Time Complexity - `O(n*k)`
> 
> Space Complexity - `O(n*k)`