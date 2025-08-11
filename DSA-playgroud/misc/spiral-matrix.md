# Spiral Matrix

Practice [here](https://leetcode.com/problems/spiral-matrix/description/)
Given an m x n matrix, return all elements of the matrix in spiral order.

## Simulation
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top = 0, bottom = matrix.size();
        int left = 0, right = matrix[0].size();

        while(true){
            //top row
            for(int i=left;i<right;i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            if(top==bottom)
                break;

            //right column
            for(int i=top;i<bottom;i++){
                result.push_back(matrix[i][right-1]);
            }
            right--;
            if(right==left)
                break;

            //bottom row
            for(int i=right;i>left;i--){
                result.push_back(matrix[bottom-1][i-1]);
            }
            bottom--;
            if(bottom==top)
                break;

            //left col
            for(int i=bottom;i>top;i--){
                result.push_back(matrix[i-1][left]);
            }
            left++;
            if(left==right)
                break;
        }
        return result;

    }
};
```

