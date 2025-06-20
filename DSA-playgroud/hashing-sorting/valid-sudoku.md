# Valid Sudoku

Practice [Here](https://leetcode.com/problems/valid-sudoku/description/)

Determine if a 9 x 9 Sudoku board is valid. 

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // check rows
        for(int i=0;i<board.size();i++)
        {
            vector<bool> hash(10, false);
            for(int j=0;j<board[i].size();j++)
            {
                char c = board[i][j];
                if(c >= '0' && c<='9'){
                    if(hash[c-'0'])
                        return false;
                    hash[c-'0'] = true;
                }
            }
        }

        // check cols
        for(int i=0;i<board.size();i++)
        {
            vector<bool> hash(10, false);
            for(int j=0;j<board[i].size();j++)
            {
                char c = board[j][i];
                if(c >= '0' && c<='9'){
                    if(hash[c-'0'])
                        return false;
                    hash[c-'0'] = true;
                }
            }
        }

        //check sub-boxes
        for(int i=0;i<board.size();i+=3)
        {
            for(int j=0;j<board[i].size();j+=3)
            {
                vector<bool> hash(10, false);
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        char c = board[k][l];
                        if(c >= '0' && c<='9'){
                            if(hash[c-'0'])
                                return false;
                            hash[c-'0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
```