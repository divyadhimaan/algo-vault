# Maximum Sum Combination

Practice [Link](https://www.geeksforgeeks.org/problems/maximum-sum-combination/0)

Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.


## Naive Approach

```cpp
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        vector<int> sums;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                sums.push_back(A[i]+B[j]);
            }
        }
        
        sort(sums.begin(), sums.end(), greater<int>());
        
        vector<int> res(sums.begin(), sums.begin()+K);
        return res;
    }
};
```


> Time Complexity: O(n^2)
>
> Space Complexity: O(n)

## Better Approach

- If we generate all possible pairs (a[i] + b[j]), we would get n² combinations — too large to compute for big n.
- But notice: the largest sums will come from combining the largest elements of each array.


###  So the intuition is:

- Sort both arrays — now the largest elements are at the end.
- Start from the largest possible sum: a[n-1] + b[n-1].
- Use a max-heap to always extract the current best (largest) sum.
- To find the next possible candidates:
 Move one step back in either a or b — that gives slightly smaller, but still promising sums.
- Repeat this process to explore only the most promising combinations, avoiding the need to calculate all n² pairs.

```cpp
class Solution {
  public:
    vector<int> maxCombinations(int n, int K, vector<int> &a, vector<int> &b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        set<pair<int,int>> st;
        priority_queue<pair<int,pair<int,int>>> pq;
        
        pq.push({a[n-1]+b[n-1], {n-1,n-1}});
        st.insert({n-1,n-1});
        
        vector<int> ans;
        while(K>0)
        {
            auto t = pq.top();
            pq.pop();
            
            
            ans.push_back(t.first);
            
            int x = t.second.first;
            int y = t.second.second;
            
            if(x-1>=0 && st.find({x-1,y})==st.end())
            {
                pq.push({a[x-1]+b[y], {x-1, y}});
                st.insert({x-1,y});
            }
            
            if(y-1>=0 && st.find({x,y-1})==st.end())
            {
                pq.push({a[x]+b[y-1], {x, y-1}});
                st.insert({x,y-1});
            }
            K--;
        }
        
        return ans;
        
    }
};

```

> Time Complexity: O(n log n + K log K)
>
> Space Complexity: O(K)