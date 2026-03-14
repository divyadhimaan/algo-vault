# Smallest Difference

Write a function that takes in two non-empty arrays of integers, finds the pair of numbers (one from each array) whose absolute difference is closest to zero, and returns an array containing these two numbers, with the number from the first array in the first position.
Note that the absolute difference of two integers is the distance between them on the real number line. For example, the absolute difference of -5 and 5 is 10, and the absolute difference of -5 and -4 is
1.
You can assume that there will only be one pair of numbers with the smallest difference.

## Implementation

- We want to find one number from each array such that their absolute difference is minimum.
- If the arrays are unsorted, comparing every pair would require: `O(n × m)`. Instead, we sort both arrays first. Sorting allows us to use a two-pointer technique.
- After sorting:
  - Numbers close in value will appear near each other in sorted order.
  - So we compare elements using two pointers.

```cpp
#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(), arrayOne.end());
  sort(arrayTwo.begin(), arrayTwo.end());

  int idxOne = 0, idxTwo = 0;

  int smallest = INT_MAX, current = INT_MAX;

  vector<int> smallestPair;

  while(idxOne < arrayOne.size() && idxTwo < arrayTwo.size()){

    int firstNum = arrayOne[idxOne];
    int secondNum = arrayTwo[idxTwo];
    
    if(firstNum < secondNum){
      current = secondNum - firstNum;
      idxOne++;
    }
    else if(firstNum > secondNum){
      current = firstNum - secondNum;
      idxTwo++;
    }else{
      return {firstNum, secondNum};
    }

    if(current < smallest){
      smallest = current;
      smallestPair = {firstNum, secondNum};
    }
  }

  
  return smallestPair;
}

```

> Time Complexity: O(nlogn + mlogm)
>
> Space Complexity: O(1)