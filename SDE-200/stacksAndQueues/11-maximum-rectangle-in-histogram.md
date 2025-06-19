# Maximum Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

## Initiution

- We check for every bar height, what will be the width.
- To check the width, we are interested in the previous smaller height(element) and next smaller height(element) -> limits.
- Find PSE and NSE and width = nse-pse-1 -> requires precomputation

## Solution

```cpp
class Solution {
public:
    void findNSE(vector<int>& nse, vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            else{
                nse[i] = n;
            }
            st.push(i);
        }
    }
    void findPSE(vector<int>& pse, vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            else{
                pse[i] = -1;
            }
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse(n);
        vector<int>pse(n);
        findNSE(nse, heights);
        findPSE(pse, heights);
        
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, heights[i]*(nse[i] - pse[i] -1));
        }
        return maxi;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(n)


## Better Solution

Dont want to use Extra space and avoid precomputation.
- Calculate PSE on the go and backtrack for NSE.
- Use a monotonic stack (increasing)

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, area, height, width;
        stack<int> stk;

        for(int i=0;i<=heights.size();i++)
        {
            while(!stk.empty() && (i==heights.size() || heights[stk.top()] >= heights[i])){
                height = heights[stk.top()];
                stk.pop();

                if(stk.empty())
                    width = i;
                else
                    width = i - stk.top() -1;

                area = height * width;
                maxArea = max(area, maxArea);
            }
            stk.push(i);
        }
        return maxArea;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)