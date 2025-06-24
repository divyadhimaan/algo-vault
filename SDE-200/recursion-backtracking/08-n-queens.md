# N Queens

The n-queens puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.

## Rules

- Every row should have one queen
- Every column should have one queen
- None of the queens should attack each other


## Approach - Backtracking

### Intiution

- Place queens row-by-row.
- For each row, try placing a queen in every column.
- Check if the position is safe (no attack in column, left/right diagonal).
- Recurse to next row; if not possible, backtrack.


```cpp
class Solution {
public:

    bool isSafe(int row, int col, vector<string>& board, int n){
        int ROW=row, COL=col;

        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row=ROW, col=COL;
        while(col>=0)
        {
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        row=ROW, col=COL;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }

    void solveNQueensUtil(int col, vector<string> &board, vector<vector<string>> &res, int n)
    {
        if(col==n)
        {
            res.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solveNQueensUtil(col+1, board, res, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);

        string s(n, '.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }

        solveNQueensUtil(0, board, res, n);
        return res;
    }
};
```

> Time Complexity: O(N*N!)
> - In the worst case, you try placing a queen in each row of each column (N rows per column): O(N!)
> - But you are checking isSafe() for each placement. Each isSafe() call takes O(N)
>
> Space Complexity: O(N<sup>2</sup>)

## Improved - hashsets

```cpp
class Solution {
public:
    void solveNQueensUtil(int col, vector<string> &board, vector<vector<string>> &res, int n, unordered_set<int> &leftRow, unordered_set<int> &upperDiag, unordered_set<int> &lowerDiag)
    {
        if(col==n)
        {
            res.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(leftRow.count(row) || upperDiag.count(row-col) || lowerDiag.count(row+col))
                continue;

            board[row][col] = 'Q';
            leftRow.insert(row);
            upperDiag.insert(row - col);
            lowerDiag.insert(row + col);

            solveNQueensUtil(col+1, board, res, n, leftRow, upperDiag, lowerDiag);

            board[row][col] = '.';
            leftRow.erase(row);
            upperDiag.erase(row - col);
            lowerDiag.erase(row + col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);

        string s(n, '.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }

        unordered_set<int> leftRow, upperDiag, lowerDiag;
        solveNQueensUtil(0, board, res, n, leftRow, upperDiag, lowerDiag);
        return res;
    }
};
```

> Time Complexity: O(N!)
>
> Space Complexity: O(N<sup>2</sup>)