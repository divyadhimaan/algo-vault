# K-th element of two Arrays

Practice [Link](https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1)

Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

## Naive Solution

```cpp
class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        vector<int> merged;

        for(int num : a) 
            merged.push_back(num);
        for(int num : b) 
            merged.push_back(num);

        sort(merged.begin(), merged.end());

        return merged[k - 1];
    }
};
```

> Time Complexity: O((n + m) * log(n + m)).
>
> Space Complexity: O(n + m)


## Better Solution - Two Pointer
```cpp
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        
        int idx = 0;
        int i=0,j=0;
        
        for(int cnt=0;cnt<k;cnt++)
        {
            if(i!=n && j!=m)
            {
                if(a[i] < b[j])
                    idx = a[i++];
                else
                    idx = b[j++];
            }else if(i<n)
                idx = a[i++];
            else
                idx = b[j++];
        }
        return idx;
    }
};
```


> Time Complexity: O(n+m)
>
> Space Complexity: O(1)