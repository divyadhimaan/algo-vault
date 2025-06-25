# Insert Delete GetRandom O(1)

Implement the `RandomizedSet` class:

`RandomizedSet()` Initializes the RandomizedSet object.
- `bool insert(int val)`: Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
- `bool remove(int val)`: Removes an item val from the set if present. Returns true if the item was present, false otherwise.
- `int getRandom()`: Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
  
You must implement the functions of the class such that each function works in average `O(1)` time complexity.

```cpp
class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val) != st.end())
            return false;
        
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(st.find(val) == st.end())
            return false;
        
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        int randIdx = rand() % st.size();
        return *next(st.begin(), randIdx);
    }
};
```

> Time Complexity: all operations in `O(1)`