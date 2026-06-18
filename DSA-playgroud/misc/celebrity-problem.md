# The Celebrity Problem

Given a square matrix mat[][] of size n x n, where mat[i][j] == 1 means person i knows person j, and mat[i][j] == 0 means person i does not know person j, find the celebrity person where,

A celebrity is defined as someone who:

Is known by everyone else
Does not know anyone (except themselves)
Return the index of the celebrity if one exists, otherwise return -1.

## Brute Force

Compute `inDegree[i]` (how many people know person i) and `outDegree[i]` (how many people person i knows) by scanning the entire matrix. A celebrity must have `inDegree == n` (everyone knows them) and `outDegree == 1` (they only "know" themselves — the diagonal `mat[i][i]` counts as 1).

```cpp
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int m = mat.size();

        vector<int> inDegree(m), outDegree(m);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                int x = mat[i][j];
                
                outDegree[i] += x;
                inDegree[j] += x;
            }
        }
        
        for(int i=0;i<m;i++){
            if(inDegree[i]==m && outDegree[i]==1)
                return i;
        }
        
        return -1;
        
    }
};
```

> Time Complexity: O(n^2)
> 
> Space Complexity: O(n)


## Better Solution: Stack

**Key insight:** given any two people A and B, one lookup `mat[A][B]` eliminates one of them as a candidate:
- If `mat[A][B] == 1` → A knows B → A can't be the celebrity (celebrities know nobody). Eliminate A.
- If `mat[A][B] == 0` → A doesn't know B → B can't be the celebrity (everyone must know the celebrity). Eliminate B.

Push all candidates onto a stack. Repeatedly pop two, eliminate one, push the survivor back. After n-1 comparisons, one candidate remains — then verify it with a full O(n) scan.

```cpp
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int m = mat.size();

        stack<int> stk;
        for(int i=0;i<m;i++){
            stk.push(i);
        }
        
        while(stk.size() > 1){
            int A = stk.top(); stk.pop();
            int B = stk.top(); stk.pop();
            
            if(mat[A][B])
                stk.push(B); // A knows B → eliminate A
            else
                stk.push(A); // A doesn't know B → eliminate B
        }
        
        int C = stk.top(); stk.pop();
        
        // verify C is actually a celebrity
        for(int i=0;i<m;i++){
            if(i==C) continue;
            if(mat[C][i] || !mat[i][C]) // C knows someone, or someone doesn't know C
                return -1;
        }
        
        return C;
        
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(n) — stack holds up to n elements


## Optimal Solution: Two Pointers

Same elimination logic as the stack, but without the stack. Use `low` and `high` pointers starting at opposite ends. Each comparison moves one pointer inward, eliminating one candidate. After the loop, `low == high` — one survivor remains, verify it.

- If `mat[low][high] == 1` → low knows high → eliminate low, move `low++`.
- If `mat[low][high] == 0` → low doesn't know high → eliminate high, move `high--`.

```cpp
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int m = mat.size();
        
        int low = 0, high = m-1;
        
        while(low < high){
            if(mat[low][high])
                low++;  // low knows high → low is not the celebrity
            else
                high--; // low doesn't know high → high is not the celebrity
        }
        
        int cel = low;
        
        // verify cel is actually a celebrity
        for(int i=0;i<m;i++){
            if(i==cel) continue;
            if(mat[cel][i] || !mat[i][cel])
                return -1;
        }
        
        return cel;
        
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(1)

---

## Comparison

| | Brute Force | Stack | Two Pointers |
|---|---|---|---|
| **Time** | O(n²) | O(n) | O(n) |
| **Space** | O(n) | O(n) | O(1) |
| **Elimination** | Full matrix scan | Pairwise via stack | Pairwise via pointers |
| **Best for** | Clarity | Natural intuition for elimination | Optimal — same idea, no extra space |