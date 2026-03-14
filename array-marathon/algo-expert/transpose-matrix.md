# Transpose Matrix

You're given a 2D array of integers matrix . Write a function that returns the transpose of the matrix.
The transpose of a matrix is a flipped version of the original matrix across its main diagonal (which runs from top-left to bottom-right); it switches the row and column indices of the original matrix.
You can assume the input matrix always has at least 1 value; however its width and height are not necessarily the same.


```cpp
using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
  int height = matrix.size();
  int width = matrix[0].size();

  vector<vector<int>> transposedMatrix(width, vector<int>(height));
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      transposedMatrix[j][i] = matrix[i][j];
    }
  }
  return transposedMatrix;
}


```


> Time Complexity: O(h × w)
>
> Space Complexity: O(h × w)