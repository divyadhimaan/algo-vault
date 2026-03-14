# Validate Subsequence

- Difficulty: Easy

Given two non-empty arrays of integers, write a function that determines whether the second array is a subsequence of the first one.
A subsequence of an array is a set of numbers that aren't necessarily adjacent in the array but that are in the same order as they appear in the array. For instance, the numbers [1, 3, 4] form a subsequence of the array [1, 2, 3, 4] , and so do the numbers [2, 4] . Note that a single number in an array and the array itself are both valid subsequences of the array.


## Brute Force

- scan the main array and try to match elements of the sequence in order.
```cpp
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int m = array.size(), n = sequence.size();
  int i = 0, j = 0;

  while(i < m && j < n){
    if(array[i] == sequence[j]){
      j++;
    }
    i++;
  }
  
  return j==n;
}

```

> Time Complexity: O(n)
>
> Space Complexity: O(1)

## Better Approach

- This approach simplifies the logic by removing the explicit pointer for the main array.
- Instead of manually managing index i, we simply iterate through the array using a for-each loop.
```cpp
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int m = array.size(), n = sequence.size();
  int j = 0;

  for(int val: array){
    if(j==n)
      break;
    if(val == sequence[j]){
      j++;
    }
  }
  
  return j==n;
}

```


> Time Complexity: O(n)
>
> Space Complexity: O(1)