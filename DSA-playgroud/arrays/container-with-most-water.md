# Container With Most Water

Practice [Here](https://leetcode.com/problems/container-with-most-water/description/)

## brute Force

- Try every pair `(i, j)`, compute the area, and update the maximum.
```cpp
int maxArea(vector<int>& height) {
    int n = height.size();
    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            maxArea = max(maxArea, h * w);
        }
    }
    return maxArea;
}

```

> Time Complexity: O(n<sup>2</sup>)
>
> Space Complexity: O(1)


## Optimal Solution: Two pointer

- Start with two pointers: left = 0, right = n - 1
- Compute area
- Move the pointer with smaller height inward (hoping for a taller line)
- Repeat until left < right

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxArea = INT_MIN;
        int n = height.size();
        
        int startIdx = 0, endIdx = n-1;
        while(startIdx<=endIdx)
        {
            int currHeight = min(height[startIdx], height[endIdx]);
            int currWidth = endIdx - startIdx;

            maxArea = max(currHeight * currWidth, maxArea);
            if(height[startIdx] < height[endIdx])
                startIdx++;
            else
                endIdx--;
        }
        return maxArea;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)