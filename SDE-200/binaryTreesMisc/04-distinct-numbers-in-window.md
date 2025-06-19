# Distinct Numbers in Window


Practice [Link](https://www.interviewbit.com/problems/distinct-numbers-in-window/)

You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE:  if B > N, return an empty array.


## Brute Force - Set

For every window, have a inner loop to check the distinct elements

```cpp
vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> result;
    if(B>A.size())
        return result;
        
    for(int i=0;i<A.size()-B+1;i++)
    {
        unordered_set<int> s;
        for(int j=0;j<B;j++)
        {
            s.insert(A[i+j]);
        }
        result.push_back(s.size());
        
    }
    return result;
    
}
```
> Time Complexity: O(N x B) -> O(N^2) -> TLE for large N
>
> Space Complexity: O(N)

## Better Approach - Sliding Window + unordered Map

```cpp
vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> result;
    if(B>A.size())
        return result;
        
    unordered_map<int,int> freq;
    int distinctCount = 0;
        
    for(int i=0;i<B;i++)
    {
        if(freq[A[i]]==0)
            distinctCount++;
        freq[A[i]]++;
    }
    result.push_back(distinctCount);
        
    for(int i=B;i<A.size();i++)
    {
        //removing outgoing freq
        if(freq[A[i-B]]==1)
            distinctCount--;
        freq[A[i-B]]--;
        
        //adding new freq
        
        if(freq[A[i]]==0)
            distinctCount++;
        freq[A[i]]++;
        result.push_back(distinctCount);
        
    }
    return result;
    
}

```

> Time Complexity: O(N)
>
> Space Complexity: O(N)

## Other Optimization

- If the input elements are bounded within a small range, we can replace map with fixed size array. (faster & less memory overhead).
