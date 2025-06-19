# Word Search
Practice [Link](https://leetcode.com/problems/word-search/description/)


Given an `m x n` grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.



## DFS - Backtracking Approach
```cpp
class Solution {
public:
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    bool search(vector<vector<char>>& board, int x, int y, string word, int idx)
    {
        if(idx == word.length())
            return true;

        if(x < 0 || x>=board.size() || y<0 || y >= board[0].size() || board[x][y] != word[idx])
            return false;

        char c = board[x][y];
        board[x][y] = '*';

        for(int dir = 0;dir<4;dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(search(board, nx,ny, word, idx+1))
                return true;
        }
        board[x][y] = c;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0])
                    if(search(board, i,j,word, 0))
                        return true;
            }
        }

        return false;
    }
};
```


> Time Complexity: O(mn * 4^L), L -> length of word
>
> Space Complexity: O(1)