# Number of NGEs

Practice [Link](https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-nges-to-the-right)


Given an array of N integers and Q queries of indices. For each query indices[i], determine the count of elements in arr that are `strictly greater` than `arr[indices[i]]` to its right (after the position indices[i]).


## Solution - 2 Stacks
```cpp
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        stack<int> descStk;
        stack<int> ascStk;
        unordered_map<int,int> mp; // index - numbeer of NGE
        
        for(int i=n-1;i>=0;i--)
        {
            while(!descStk.empty() && descStk.top() <= arr[i])
            {
                ascStk.push(descStk.top());
                descStk.pop();
            }
            mp[i] = descStk.size();
            descStk.push(arr[i]);
            
            while(!ascStk.empty()){
                descStk.push(ascStk.top());
                ascStk.pop();
            }
        }
        vector<int> ans;
        for(int i=0;i<indices.size();i++)
        {
            int idx = indices[i];
            ans.push_back(mp[idx]);
        }
        return ans;
       
    }
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)
