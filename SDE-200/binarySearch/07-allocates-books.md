# Allocate Books

Practice [Link](https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)

You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.


## Linear Search

### Intiution

- the minimum number of pages that are assignable to any student is the maximum in the guven array. `low = max(arr)`
- And the maximum number of pages assigned can be the summation of all pages. `high = sum(arr)`

```cpp
cclass Solution {
  public:
    int countStudents(vector<int> &arr, int maxPages)
    {
        int numberOfStudents = 1;
        long long currentPages=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(currentPages + arr[i] <= maxPages){
                currentPages += arr[i];
            }
            else{
                currentPages = arr[i];
                numberOfStudents++;
            }
        }
        return numberOfStudents;
    }  
    
    int findPages(vector<int> &arr, int k) {
        int numberOfBooks = arr.size();
        
        if(k>numberOfBooks)
            return -1;
            
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        

        for(int pages = low; pages<=high;pages++)
        {
            if(countStudents(arr, pages) <= k){
                return pages;
            }
        }
        return -1;
    }
};
```

> Time complexity: O(N * (sum(arr[])-max(arr[])+1)) ~ O(n^2) --> TLE
>
> Space Complexity: O(1)

## Binary Search

```cpp
class Solution {
  public:
    int countStudents(vector<int> &arr, int maxPages)
    {
        int numberOfStudents = 1;
        long long currentPages=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(currentPages + arr[i] <= maxPages){
                currentPages += arr[i];
            }
            else{
                currentPages = arr[i];
                numberOfStudents++;
            }
        }
        return numberOfStudents;
    }  
    int findPages(vector<int> &arr, int k) {
        int numberOfBooks = arr.size();
        
        if(k>numberOfBooks)
            return -1;
            
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            int requiredStudents = countStudents(arr, mid);
            if(requiredStudents <= k){
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return low;
    }
};
```


> Time complexity: O(N * log(sum(arr[])-max(arr[])+1)) ~ O(n*logn) 
>
> Space Complexity: O(1)
