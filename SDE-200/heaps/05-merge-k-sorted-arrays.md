# Merge K sorted arrays

Practice [Link](https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1)

Given `k` sorted arrays arranged in the form of a matrix of size `k * k`. The task is to merge them into one sorted array. 

Return the merged sorted array


## Naive Approach

- Combine all k sorted arrays -> O(k)
- Sort the combined array -> O(nlogn), where n: total number of elements in k arrays

## Using Min heap

> This Approach would work for diff/same size of arrays.

- Use a min-heap to store the current smallest elements.
- Each entry in the heap is of the form {value, {array_index, element_index}}.
- Initially push the first element of each array into the heap.
- Repeatedly:
  - Pop the smallest element.
  - Add it to the result.
  - Push the next element from the same array (if any) into the heap.

```cpp
typedef pair<int,pair<int,int>> ppi;
class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        
        //insert first element of every array
        for(int i=0;i<arr.size();i++)
            pq.push({arr[i][0], {i,0}});
            
        
        //keep picking the top element from minHeap and adding next from the same array.
        vector<int> ans;
        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            
            ans.push_back(t.first);
            
            int x = t.second.first;
            int y = t.second.second;
            
            if(y+1 < arr[x].size())
                pq.push({arr[x][y+1], {x, y+1}});
        }
        return ans;
    }
};
```

> Time Complexity: `O(nlogk)`, each heap operation is log k and there are n elements total
> 
> Space Complexity: `O(n) + O(k)`