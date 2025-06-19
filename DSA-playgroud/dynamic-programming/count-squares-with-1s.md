# Count Square Submatrices with All Ones


Practice [Link](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

## Brute Force
In order to solve this question, we will first try the brute force approach. In the brute force approach, we will just check for every cell(i, j)(if the cell contains 1) that if there exists a k-sized square where k can range from 1 to min(n-i, m-j)(considering 0-based indexing). The implementation will be very much complex. So, we will move on to the optimized approach i.e. the dynamic programming approach.



## Optimal Approach
`dp[i][j]` will signify, how many squares end at the cell `(i, j) `


### Steps
The algorithm steps are as follows:

- First, we need to create a dp array of the same size as the matrix.
- Then, we will copy the values of the first row and first column of the matrix as it is to the dp array.
- Then, we will start iterating over the rest of the cells and we will observe two cases:
  - If the cell (i, j) contains 0, we will set the value 0 to the cell dp[i][j].
  - If the cell (i, j) contains 1, we will first find the minimum value among the adjacent three cells i.e. min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]). And with that minimum value, we will add 1 and set it to the cell dp[i][j]. The formula will look like the following:
    `dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) +1`
- After filling all the cells in this way, we will just add all the values of the dp array to get the total sum. And this total sum will be the final answer.

## Implementation

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int squares=0;
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i=1;i<m;i++){
            dp[i][0] = matrix[i][0];
            squares += dp[i][0];
        }
        
        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j];
            squares += dp[0][j];
        }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                    dp[i][j] =0;
                else
                    dp[i][j] = 1+ min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                squares += dp[i][j];
            }
        }
        return squares;
    }
};
```


> Time Complexity: O(m * n)
>
> Space Complexity: O(m * n)