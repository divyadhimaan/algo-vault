# Set Matrix Zeros

Practice [here](https://leetcode.com/problems/set-matrix-zeroes/description/)

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.


## Set Approach


- Splitting it into two passes:
  - Mark first
  - Clear later
```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        // set rows zero
        for(int row: rows)
        {
            cout<<"setting row: "<<row<<endl;
            for(int j=0;j<matrix[0].size();j++)
                matrix[row][j] = 0;
        }

        // set cols zero
        for(int col: cols)
        {
            cout<<"setting col: "<<col<<endl;
            for(int j=0;j<matrix.size();j++)
                matrix[j][col] = 0;
        }
    }
};
```

> Time Complexity: O(m*n)
>
> Space Complexity: O(m+n)

## Greedy Approach

`Analogy`: Some buildings have broken water pipes (0), and if one breaks, you need to shut off water to that entire street (row) and entire avenue (column).

But here’s the twist — you can’t carry a separate notebook to remember which streets and avenues to shut off. You can only leave notes taped to the city itself:

- While walking around, you put warning signs at the start of each street (row’s first cell) and the start of each avenue (column’s first cell) whenever you see a broken pipe.
- You also keep a special mental note (isCol) for the first avenue, because it overlaps with the first street’s first building (matrix[0][0]), and you don’t want to lose track of it.
- After marking, you make a second pass, shutting down water (setting 0s) for every building whose row start or column start has a warning sign.
- Finally, you separately handle the first street and the first avenue using your notes, because they were the storage area for all your warnings.
This way, the “city” remembers the problem spots for you — no extra storage notebooks needed.


```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol = false;

        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][0]==0)
                isCol = true;

            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }

        if(matrix[0][0]==0)
            for(int j=0;j<matrix[0].size();j++)
                matrix[0][j]=0;

        if(isCol)
            for(int i=0;i<matrix.size();i++)
                matrix[i][0]=0;
    }
};
```

> Time Complexity: O(m*n)
>
> Space Complexity: O(1)