# Largest Rectangle in a Histogram

Practice [Link](https://leetcode.com/problems/largest-rectangle-in-histogram/description/)

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.



## Brute Force

You’re treating each bar at index i as the shortest bar in a rectangle and:

- Looking Left:
  - Move left from i, and count how far you can extend the rectangle until a smaller bar breaks the streak.
- Looking Right:
  - Move right from i, and do the same.
- Area:
  - The width of the rectangle is (left + right + 1) (including the current bar).
  - So, area = height[i] * (left + right + 1).


```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        for(int i=0;i<heights.size();i++)
        {
            int left=0;
            for(int j=i-1;j>=0;j--)
                if(heights[j]>= heights[i])
                    left++;
                else
                    break;


            int right=0;
            for(int j=i+1;j<heights.size();j++)
                if(heights[j]>= heights[i])
                    right++;
                else
                    break;

            int area = heights[i] * (left+right+1);
            maxArea = max(area, maxArea);

        }
        return maxArea;
    }
};
```

> Time Complexity: O(n^2)
>
> Space Complexity: O(1)

## Using Stack

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();

        stack<int> stk;
        vector<int> leftSmall(n), rightSmall(n);

        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();

            if(stk.empty())
                leftSmall[i]=0;
            else
                leftSmall[i] = stk.top()+1;

            stk.push(i);
        }

        while(!stk.empty())
            stk.pop();

        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();

            if(stk.empty())
                rightSmall[i]=n-1;
            else
                rightSmall[i] = stk.top()-1;

            stk.push(i);
        }

        for(int i=0;i<n;i++)
        {
            int area = (rightSmall[i]-leftSmall[i]+1) * heights[i];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
```

> Time Complexity: O(n) - Needs alot of traversal
> For finding leftSmaller -> O(n) + O(n), rightSmaller -> O(n) + O(n), finding area -> O(n)
> 
> Space Complexity: O(n)


## Optimal Approach


```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        stack<int> stk;

        for(int i=0;i<=heights.size();i++)
        {
            while(!stk.empty() && (i==heights.size() || heights[stk.top()]>=heights[i]))
            {
                int height = heights[stk.top()];
                stk.pop();

                int width=0;
                if(stk.empty())
                    width = i;
                else
                    width = i - stk.top()-1;

                int area = height*width;
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
> Space Complexity: O(n)