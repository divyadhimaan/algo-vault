# Maximal Rectangle

Practice [Link](https://leetcode.com/problems/maximal-rectangle/description/)


Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.


We will refer the problem: Find Max area in a histogram, Using thtat, we will find the area for every row, considering all the above rows are part of the current histogram height.
```cpp
class Solution {
public:
    int maxAreaInHistogram(vector<int>& heights)
    {
        stack<int> stk;
        int maxArea=0;

        for(int i=0;i<=heights.size();i++)
        {
            while(!stk.empty() && (i==heights.size() || heights[stk.top()] >= heights[i]))
            {
                int height = heights[stk.top()];
                stk.pop();

                int width = 0;
                if(stk.empty())
                    width= i;
                else
                    width = i - stk.top() -1;

                maxArea = max(maxArea, height*width);
            }

            stk.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                    heights[j]++;
                else
                    heights[j]=0;
            }
            int area = maxAreaInHistogram(heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
```

> Time Complexity: O(m * n)
>
> Space Complexity: O(n)