# Median of 2 sorted Arrays


## Naive Solution

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Get the sizes of both input arrays.
        int n = nums1.size();
        int m = nums2.size();

        // Merge the arrays into a single sorted array.
        vector<int> merged;
        for (int i = 0; i < n; i++) {
            merged.push_back(nums1[i]);
        }
        for (int i = 0; i < m; i++) {
            merged.push_back(nums2[i]);
        }

        // Sort the merged array.
        sort(merged.begin(), merged.end());

        // Calculate the total number of elements in the merged array.
        int total = merged.size();

        if (total % 2 == 1) {
            // If the total number of elements is odd, return the middle element as the median.
            return static_cast<double>(merged[total / 2]);
        } else {
            // If the total number of elements is even, calculate the average of the two middle elements as the median.
            int middle1 = merged[total / 2 - 1];
            int middle2 = merged[total / 2];
            return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2.0;
        }
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i=0, j=0;
        int idx1=0,idx2=0;
        for(int cnt=0;cnt<=(n+m)/2;cnt++)
        {
            idx2 = idx1;
            if(i!=n && j!=m)
            {
                if(nums1[i]> nums2[j])
                    idx1 = nums2[j++];
                else
                    idx1 = nums1[i++];
            }else if(i<n){
                idx1 = nums1[i++];
            }else{
                idx1 = nums2[j++];
            }
        }

        if((n+m)%2 == 1)
            return (double)idx1;
        else
            return (double )((double)(idx1+idx2))/2.0;
    }
};
```


> Time Complexity: O(n+m)
>
> Space Complexity: O(1)