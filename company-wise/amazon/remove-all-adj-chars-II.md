# Remove All Adjacent Duplicates in String II
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

## Approach 1: Stack + Frequency tracking

```cpp

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.length();
        vector<int> continousFreqCount(n, 1);
        stack<int> st;
        string ans;
        
        st.push(0);
        
        for(int i = 1; i < n ; i++){
            
            if(!st.empty()){
                if(s[st.top()]==s[i]) continousFreqCount[i] = continousFreqCount[st.top()] + 1;
            }
            
            st.push(i);
            
            if(continousFreqCount[st.top()] == k){
                for(int i = 0 ; i < k ; i++){
                    st.pop();
                }
            }
            
        }
        
        while(!st.empty()){
            
            ans += s[st.top()];
            st.pop();
            
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(n)


## Approach 2: 

```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k)
            return s;

        stack<pair<char, int>> stk;

        for(int i=0;i<n;i++){
            if(stk.empty() || stk.top().first != s[i])
                stk.push({s[i], 1});

            else{
                stk.top().second++;
            }

            if(stk.top().second == k)
                stk.pop();
        }

        string res;

        while(!stk.empty()){
            auto curr = stk.top();
            stk.pop();

            while(curr.second--){
                res.push_back(curr.first);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
```
> Time Complexity: O(n)
>
> Space Complexity: O(n)