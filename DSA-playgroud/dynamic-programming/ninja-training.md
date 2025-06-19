# Ninja Training

Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .

Practice [Link](https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training)


## Implementation

### A. Recursive Approach
```cpp

class Solution {
  public:
  
    int maximumPointsUtil(vector<vector<int>>& arr, int day, int lastChoice)
    {
        if(day<0)
        {
           return 0;
        }
            
            
        int maxi = 0;
        for(int i=0;i<3;i++)
        {
            if(i!=lastChoice)
            {
                maxi = max(maxi, arr[day][i] + maximumPointsUtil(arr, day-1, i));
            }
        }
        return maxi;
    }
  
    int maximumPoints(vector<vector<int>>& arr) {
        return maximumPointsUtil(arr, arr.size()-1, -1);
    }
};

```
> Time Limit Exceeded


### B. Memoization

```cpp
class Solution {
  public:
  
    int maximumPointsUtil(vector<vector<int>>& arr, int day, int lastChoice, vector<vector<int>> &memo)
    {
        if(day<0)
        {
           return 0;
        }
        
        if(memo[day][lastChoice]!= -1)
            return memo[day][lastChoice];
            
            
        int maxi = 0;
        for(int i=0;i<3;i++)
        {
            if(i!=lastChoice)
            {
                maxi = max(maxi, arr[day][i] + maximumPointsUtil(arr, day-1, i, memo));
            }
        }
        return memo[day][lastChoice] = maxi;
    }
  
    int maximumPoints(vector<vector<int>>& arr) {
        vector<vector<int>> memo(arr.size(), vector<int>(4, -1));
        return maximumPointsUtil(arr, arr.size()-1, 3, memo);
    }
};
```

> Time Complexity - O(n * 4 * 3), There are N*4 states and for every state, we are running a for loop iterating three times.
> 
> Space Complexity - O(N) + O(N*4),  We are using a recursion stack space(O(N)) and a 2D array (again O(N*4)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)

### B. Tabulation Solution

```cpp
cclass Solution {
  public:
  
  
    int maximumPoints(vector<vector<int>>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(4, 0));
        
        dp[0][0] = max(arr[0][1], arr[0][2]);
          dp[0][1] = max(arr[0][0], arr[0][2]);
          dp[0][2] = max(arr[0][0], arr[0][1]);
          dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        
        for(int day=1;day<arr.size();day++)
        {
            for(int lastChoice=0;lastChoice<4;lastChoice++)
            {
                dp[day][lastChoice] = 0;
                for(int task = 0;task<3;task++)
                {
                    if(lastChoice != task)
                    {
                        int currPoints = arr[day][task] + dp[day-1][task];
                        dp[day][lastChoice] = max(dp[day][lastChoice], currPoints);
                    }
                }
                
            }
        }
        
        return dp[arr.size()-1][3];
    }
};
```

> Time Complexity - O(n * 4 * 3)
> 
> Space Complexity - O(N * 4)
 

### Tabulation : Space Optimized

```cpp

class Solution {
  public:
  
  
    int maximumPoints(vector<vector<int>>& arr) {
          
          vector<int> prev(4, 0);
          
          prev[0] = max(arr[0][1], arr[0][2]);
          prev[1] = max(arr[0][0], arr[0][2]);
          prev[2] = max(arr[0][0], arr[0][1]);
          prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        
        
        for(int day=1;day<arr.size();day++)
        {
            vector<int> curr(4, 0);

            for(int lastChoice=0;lastChoice<4;lastChoice++)
            {
                curr[lastChoice] = 0;
                for(int task = 0;task<3;task++)
                {
                    if(lastChoice != task)
                    {
                        curr[lastChoice] = max(curr[lastChoice], arr[day][task] + prev[task]);
                    }
                }
            }
            prev = curr;
        }
        
        return prev[3];
    }
};

```

> Time Complexity - O(n * 4 * 3)
> 
> Space Complexity - O(4)