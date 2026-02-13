# Union of two sorted arrays

Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.

The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.


## Brute Force: hashset

```cpp
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        set<int> Union;

        for(int i=0;i<nums1.size();i++){
            Union.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            Union.insert(nums2[i]);
        }

        vector<int> result(Union.begin(), Union.end());

        return result;
    }
};
```

> Time Complexity: O(n + m + klogk), where k -> unique ele
>
> Space Complexity: O(k)

## Optimal Approach

```cpp
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int m = nums1.size();
        int n = nums2.size();

        int i=0, j=0;

        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                if(result.size()==0 || result.back() != nums1[i]){
                    result.push_back(nums1[i]);
                }
                i++;
            }else{
                if(result.size()==0 || result.back() != nums2[j]){
                    result.push_back(nums2[j]);
                }
                j++;
            }
        }

        while(i<m){
            if(result.back() != nums1[i]){
                result.push_back(nums1[i]);
            }
            i++;
        }

        while(j<n){
            if(result.back() != nums2[j]){
                result.push_back(nums2[j]);
            }
            j++;
        }


        return result;
    }
};
```

> Time Complexity: O(n + m), 
>
> Space Complexity: O(n + m)
