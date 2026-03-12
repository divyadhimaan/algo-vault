# Sorted Squared Array


- Even though the initial array is sorted, squaring the elements can disturb the order because negative numbers become positive after squaring.
> [-7, -3, -1, 4, 8]
> 
> Squares → [49, 9, 1, 16, 64]

- This is not sorted anymore, so we must handle ordering carefully.

## Brute Force
- The simplest idea is:
  - Square every number in the array.
  - Since squaring might disturb the order, sort the squared values again.
  
```cpp
#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  vector<int> result;
  for(auto num: array){
    result.push_back(num*num);
  }
  sort(result.begin(), result.end());
  return result;
}

```

> Time Complexity: O(nlogn)
>
> Space Complexity: O(n)


## Optimal Approach

- Observation: In a sorted array, the largest square will always come from one of the ends.
- Use two pointers:
  - smallerIdx → start of array
  - largerIdx → end of array
- Compare the absolute values of the two ends.
- The larger absolute value produces the larger square.
- Place that square at the end of the result array.
- Move the corresponding pointer inwards.

```cpp
#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  vector<int> resultArray(array.size(), 0);
  int smallerIdx = 0;
  int largerIdx = array.size()-1;

  for(int idx = array.size()-1; idx >= 0; idx--){
    int smallerVal = array[smallerIdx];
    int largerVal = array[largerIdx];

    if(abs(smallerVal) > abs(largerVal)){
      resultArray[idx] = smallerVal * smallerVal;
      smallerIdx++;
    }else{
      resultArray[idx] = largerVal * largerVal;
      largerIdx--;
    }
  }
  
  return resultArray;
}

```

> Time Complexity: O(n)
>
> Space Complexity: O(n)