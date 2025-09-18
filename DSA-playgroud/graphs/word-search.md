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


| Approach           | Best For                             | Complexity             | Notes                            |
| ------------------ | ------------------------------------ | ---------------------- | -------------------------------- |
| DFS + Backtracking | Single word                          | `O(m*n*4^L)`           | ✔ Your current                   |
| Trie + DFS         | Multiple word search                 | `O(M*N + total chars)` | 🔥 Efficient pruning             |
| BFS                | Level-order or shortest-path variant | Similar                | ❌ Usually slower                 |
| DFS + Memoization  | Repeating board patterns             | Higher space           | 🧠 Rarely worth for this problem |


## Follow Up

Could you use search pruning to make your solution faster with a larger board?

1. Early frequency pruning (pre-check):
   - Count the frequency of each character in the board.
   - If the word contains a character more times than the board, return false immediately.
   - Example:
     - Word = "zzz", board has only 1 z. → no need to DFS at all.
2. Reverse search optimization:
   - When the word has characters with different frequencies, start DFS from the rarest character in the board.
   - This reduces branching because you start from a location with fewer possible matches.
   - Example:
     - Word = "ABAABZ", board has only one Z. → start search from Z.

```cpp
bool exist(vector<vector<char>>& board, string word) {
    unordered_map<char,int> freqBoard, freqWord;

    for(auto &row: board)
        for(char c: row)
            freqBoard[c]++;

    for(char c: word)
        freqWord[c]++;

    // Early frequency pruning (pre-check)
    for(auto &p: freqWord) {
        if(freqBoard[p.first] < p.second) 
            return false; // word impossible
    }

    // Optionally: if last char is rarer than first char in board, reverse word
    if(freqBoard[word[0]] > freqBoard[word.back()])
        reverse(word.begin(), word.end());

    // Now do your DFS
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[0].size();j++) {
            if(find(board, word, 0, i, j))
                return true;
        }
    }
    return false;
}
```