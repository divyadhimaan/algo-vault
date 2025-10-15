# Sudoku Solver
Create a program that fills in the blank cells in a Sudoku puzzle to solve it.

Every sudoku solution needs to follow to these guidelines:

1) In every row, the numbers 1 through 9 must appear exactly once.
2) In every column, the numbers 1 through 9 must appear exactly once.
3) In each of the grid's nine 3x3 sub-boxes, the numbers 1 through 9 must appear exactly once.

Empty cells are indicated by the '.' character.

## Brute Force

```cpp
class Solution {
public:

    bool foundSafeDigit(vector<vector<char> >& board, int row, int col, char num){
        for(int i=0;i<9;i++)
        {
            if(board[i][col] == num)
            {
                return false;
            }
        }
        
        for(int i=0;i<9;i++)
        {
            if(board[row][i] == num)
                return false;
        }
        
        int s = sqrt(9);
        int rowStart = row - (row%s);        
        int colStart = col - (col%s);
        
        for(int r = rowStart; r < rowStart+s; r++)
        {
            for(int c = colStart; c < colStart+s; c++)
            {
                if(board[r][c] == num)
                    return false;
            }
        }
        return true;
    }

    bool solveSudokuUtil(vector<vector<char> >& board){
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char digit='1'; digit<='9';digit++)
                    {
                        if(foundSafeDigit(board, i, j, digit))
                        {
                            board[i][j]=digit;
                            if(solveSudokuUtil(board))
                                return true;
                            else 
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }

    void solveSudoku(vector<vector<char> >& board) {
    
        solveSudokuUtil(board);
    }
};
```





## Optimized Safe Check

- `3*(row/3)` → starting row of subgrid
- `3*(col/3)` → starting column of subgrid
- `i/3` → row offset in subgrid
- `i%3` → column offset in subgrid

### Example

For Cell = (4,5)

1. Subgrid
   - `row/3` -> (4/3) -> 1
   - `col/3`-> (5/3) -> 1
2. starting row and col of subgrid
   - `3*(row/3)` -> 3*1 -> 3 -> rows (3..5)
   - `3*(col/3)` -> 3*1 -> 3 -> cols(3..5)
3. Loop 0 -> 8
    
   | i | i/3 | i%3 | cell checked |
   |---|-----|-----|--------------|
   | 0 | 0   | 0   | (3,3)        |
   | 1 | 0   | 1   | (3,4)        |
   | 2 | 0   | 2   | (3,5)        |
   | 3 | 1   | 0   | (4,3)        |
   | 4 | 1   | 1   | (4,4)        |
   | 5 | 1   | 2   | (4,5)        |
   | 6 | 2   | 0   | (5,3)        |
   | 7 | 2   | 1   | (5,4)        |
   | 8 | 2   | 2   | (5,5)        |


```cpp
class Solution {
public:

    bool foundSafeDigit(vector<vector<char> >& board, int row, int col, char digit){
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==digit)
                return false;
            if(board[i][col]==digit)
                return false;
            int subGridRowIdx = (3*(row/3))+(i/3);
            int subGridColIdx = (3*(col/3))+(i%3);

            if(board[subGridRowIdx][subGridColIdx]==digit)
                return false;
        }
        return true;
    }

    bool solveSudokuUtil(vector<vector<char> >& board){
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char digit='1'; digit<='9';digit++)
                    {
                        if(foundSafeDigit(board, i, j, digit))
                        {
                            board[i][j]=digit;
                            if(solveSudokuUtil(board))
                                return true;
                            else 
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }

    void solveSudoku(vector<vector<char> >& board) {
    
        solveSudokuUtil(board);
    }
};
```

> Time Complexity: `O(9^(number of empty cells))`, where each empty cell can have 9 possibilities, in the worst case, it can explore all possibilities.
> 
> Space Complexity:`O(m*n)`, due to the implicit stack space used by the recursive calls, where m is the number of rows and n is the number of columns in the board.