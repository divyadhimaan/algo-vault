# MinHeap/MaxHeap Implementation

This implementation would work for both maxheap and minheap, based on a flag `isMinHeap`
> isMinHeap -> `true` -> minHeap


```cpp

class BinaryHeap {
    vector<int> heap;
    bool isMinHeap;

    bool compare(int a, int b) {
        return isMinHeap ? (a < b) : (a > b);
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    BinaryHeap(bool minHeap = true) {
        isMinHeap = minHeap;
    }

    int parent(int i) { 
        return (i - 1) / 2; 
    }

    int left(int i) { 
        return 2 * i + 1; 
    }

    int right(int i) { 
        return 2 * i + 2; 
    }

    void insert(int key) {
        heap.push_back(key);
        int i = heap.size() - 1;

        // Heapify up
        while (i != 0 && compare(heap[i], heap[parent(i)])) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Heapify (downward)
    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int target = i;

        if (l < heap.size() && compare(heap[l], heap[target]))
            target = l;

        if (r < heap.size() && compare(heap[r], heap[target]))
            target = r;

        if (target != i) {
            swap(heap[i], heap[target]);
            heapify(target);
        }
    }

    // Get min (or max)
    int getTop() {
        if (heap.empty())
            return -1;
        return heap[0];
    }

    // Extract min (or max)
    int extractTop() {
        if (heap.empty())
            return -1;

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);

        return root;
    }

    // Delete key at index i
    void deleteKey(int i) {
        if (i >= heap.size())
            return;

        // For minHeap: decrease to INT_MIN, for maxHeap: increase to INT_MAX
        decreaseKey(i, isMinHeap ? INT_MIN : INT_MAX);
        extractTop();
    }

    // Decrease key at index i to new_val
    void decreaseKey(int i, int new_val) {
        heap[i] = new_val;

        // Heapify up
        while (i != 0 && compare(heap[i], heap[parent(i)])) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Utility: print heap
    void printHeap() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

```

## Time Complexities

| Operation               | Time Complexity | Explanation                         |
|-------------------------|-----------------|-------------------------------------|
| **Insert()**            | O(log n)        | Heapify up from the inserted node   |
| **heapify()**           | O(log n)        | Heapify down to fix heap property   |
| **getMin() / getMax()** | O(1)            | Root element access                 |
| **extractMin() / extractMax()** | O(log n) | Swap & heapify down                |
| **deleteKey()**         | O(log n)        | Decrease key + extract              |
| **decreaseKey()**       | O(log n)        | Heapify up                          |
