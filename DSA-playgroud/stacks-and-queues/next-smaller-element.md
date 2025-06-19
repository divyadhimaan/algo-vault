# Next Smaller Element

Practice [Link](https://www.interviewbit.com/problems/nearest-smaller-element/)


ThGiven an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,
- G[i] for an element A[i] = an element A[j] such that 
- j is maximum possible AND 
- j < i AND
- A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

## Intiution
-  We maintain a stack called monotonic stack (increasing)

## Solution - Monotonic Stack

```cpp
vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans(A.size(), -1);
    stack<int> stk;

    for(int i=0;i<A.size();i++)
    {
        while(!stk.empty() && stk.top() >= A[i])
            stk.pop();
        if(!stk.empty())
            ans[i] = stk.top();
        stk.push(A[i]);
    }
    return ans;
}

```

> Time Complexity: O(n)
> 
> Space Complexity: O(n)