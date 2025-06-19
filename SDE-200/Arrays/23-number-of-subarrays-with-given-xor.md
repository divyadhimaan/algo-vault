# Count Number of Subarrays with Given Xor

Practice [Link](https://www.interviewbit.com/problems/subarray-with-given-xor/)


Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.

## Brute Force

- loop(i) Check every index to be the starting index of subarray
- loop(j) for i, check every index to be ending index 
  
```cpp
int Solution::solve(vector<int> &A, int B) {
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        int currXor = 0;
        for(int j=i;j<A.size();j++)
        {
            currXor = currXor ^ A[j];
            if(currXor == B)
                count++;
        } 
    }
    return count;
}
```

> Time Complexity: O(n^2)
>
> Space Complexity: O(1)

## Optimal Approach

- Compute preXor at every step and check if current subarray has given XOR
  
- Observation:
  - Lets suppose the prefix XOR of subarray ending at index `i` is `Xr`.
  - In this subarray we will search another subarray ending at index `i`, with XOR `k`.
  - If it exists, the XOR for rest of subarray will be `Xr ^ k`
    - x ^ k = Xr
    - x ^ k ^ k = Xr ^ k
    - x = Xr ^ k
  

- First, we will declare a map to store the prefix XORs and their counts.
- Then, we will set the value of 0 as 1 on the map.
- Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
- For each index i, we will do the following:
    - We will XOR the current element i.e. arr[i] to the existing prefix XOR.
    - Then we will calculate the prefix XOR i.e. xr^k, for which we need the occurrence.
    - We will add the occurrence of the prefix XOR xr^k i.e. mpp[xr^k] to our answer.
    - Then we will store the current prefix XOR, xr in the map increasing its occurrence by 1.

```cpp
int Solution::solve(vector<int> &A, int B) {
    int cnt=0, xr=0;
    unordered_map<int,int> mp;
    mp[xr]=1;
    
    for(int i=0;i<A.size();i++)
    {
        xr = xr ^ A[i];
        
        int x = xr ^ B;
        
        cnt += mp[x];
        
        mp[xr]++;
    }
    return cnt;
}

```

> Time Complexity: O(n)
>
> Space Complexity: O(n)