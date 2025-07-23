
# Commonly Used Data structures - their time complexities and differences
Checkout the time complexities for commonly used data structures.

## unordered_set [STL]

| **Operation**      | **Average Time Complexity** | **Worst-Case Time Complexity** | **Notes**                                                               |
| ------------------ | --------------------------- | ------------------------------ | ----------------------------------------------------------------------- |
| `insert()`         | O(1)                        | O(n)                           | Worst-case when many elements hash to the same bucket (poor hash func). |
| `erase(key)`       | O(1)                        | O(n)                           | Removes by key. Worst case if hash collisions occur.                    |
| `find(key)`        | O(1)                        | O(n)                           | Returns iterator to key if present.                                     |
| `count(key)`       | O(1)                        | O(n)                           | Returns 0 or 1 since elements are unique.                               |
| `size()`           | O(1)                        | O(1)                           | Returns number of elements.                                             |
| `empty()`          | O(1)                        | O(1)                           | Checks if set is empty.                                                 |
| `clear()`          | O(n)                        | O(n)                           | Removes all elements.                                                   |
| `begin()`, `end()` | O(1)                        | O(1)                           | Returns iterator to beginning/end.                                      |



## ordered_set [STL]

| **Operation**      | **Time Complexity** | **Notes**                                            |
| ------------------ | ------------------- | ---------------------------------------------------- |
| `insert()`         | O(log n)            | Inserts element and maintains order.                 |
| `erase(key)`       | O(log n)            | Removes element by key.                              |
| `find(key)`        | O(log n)            | Returns iterator to key if present.                  |
| `count(key)`       | O(log n)            | Returns 0 or 1.                                      |
| `lower_bound(key)` | O(log n)            | Returns iterator to first element not less than key. |
| `upper_bound(key)` | O(log n)            | Returns iterator to first element greater than key.  |
| `size()`           | O(1)                | Returns number of elements.                          |
| `empty()`          | O(1)                | Checks if set is empty.                              |
| `clear()`          | O(n)                | Removes all elements.                                |
| `begin()`, `end()` | O(1)                | Returns iterator to smallest/largest element.        |


## unordered_set V/s ordered_set
| Feature       | `set` (ordered)        | `unordered_set` (hash-based) |
| ------------- | ---------------------- | ---------------------------- |
| Internal DS   | Red-Black Tree (BST)   | Hash Table                   |
| Order         | Maintains sorted order | No order                     |
| Search/Insert | O(log n)               | O(1) avg, O(n) worst         |
| Use case      | When order matters     | When constant time matters   |
