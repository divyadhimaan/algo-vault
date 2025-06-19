# Trapping Rainwater

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

## BRUTE FORCE APPROACH


```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        for(int i=0;i<height.size();i++)
        {
            int leftMax=0, rightMax=0;
            for(int j=i;j>=0;j--)
            {
                leftMax = max(leftMax, height[j]);
            }
            
            for(int j=i;j<height.size();j++)
            {
                rightMax = max(rightMax, height[j]);
            }
            
            ans += min(leftMax, rightMax) - height[i];
        }
        return ans;
    }
};
```
> TC-> O(n^2)
> 
> SC-> O(1)

## DP APPROACH


```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans=0;
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        
        leftMax[0] = height[0];
        for(int i=1;i<height.size();i++)
        {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        
        rightMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        
        for(int i=1;i<height.size()-1;i++)
        {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};
```


> TC-> O(3n)
> 
> SC-> O(n)
> 3 traversals required


## TWO POINTER APPROACH

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=0, rightMax=0;
        int ans=0;
        
        int left = 0, right = height.size()-1;
        
        while(left<right)
        {
            if(height[left] < height[right])
            {
                if(height[left]>leftMax)
                {
                    leftMax = height[left];
                    
                }else
                {
                    ans += leftMax - height[left];
                }
                left++;
            }else {
                if(height[right]>rightMax)
                {
                    rightMax = height[right];
                    
                }else
                {
                    ans += rightMax - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
```

> TC- >O(n) 
> 
> SC -> O(1)
>

## Monotonic Stack

```cpp
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(); // Number of elements in the height array
        int water = 0;         // Initialize the total trapped water volume
        vector<int> stack;     // Stack to store indices of height elements
        // Iterate through the heights
        for (int right = 0; right < n; right++)
        {
            // Process each height to trap water
            while (!stack.empty() && height[stack.back()] < height[right])
            {
                // If the current height is greater than the height at the top of the stack
                int mid = stack.back(); // Get the index of the height at the top of the stack
                stack.pop_back();       // Pop the index from the stack
                // If the stack becomes empty, no more water can be trapped
                if (stack.empty())
                    break;
                int left = stack.back();                                                      // Get the index of the next height from the top of the stack
                int minHeight = min(height[right] - height[mid], height[left] - height[mid]); // Calculate the minimum height of the two borders
                int width = right - left - 1;                                                 // Calculate the width between the left and right borders
                water += minHeight * width;                                                   // Calculate the trapped water volume and add it to the total
            }
            stack.push_back(right); // Push the current index onto the stack
        }
        return water; // Return the total trapped water volume
    }
};
```


> TC- >O(n) 
> 
> SC -> O(n)
>