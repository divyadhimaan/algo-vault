# Merge two sorted arrays without extra space

Given two integer arrays nums1 and nums2. Both arrays are sorted in non-decreasing order.

Merge both the arrays into a single array sorted in non-decreasing order.

- The final sorted array should be stored inside the array nums1 and it should be done in-place.
- nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s.
- nums2 has a length of n.

## Optimal Approach

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;

        int idx = nums1.size()-1;
        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]){
                nums1[idx] = nums1[i--];
            }else{
                nums1[idx] = nums2[j--];
            }
            idx--;
        }

    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)