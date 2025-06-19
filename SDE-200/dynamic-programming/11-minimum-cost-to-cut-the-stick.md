# Minimum Cost to cut the stick

Practice [Link](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/)

Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:

![Alt text](/images/dp-b.png)

Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.


## Intiution

- We have to find the minimum cost of cutting my trying different orders to cut.
![Alt text](/images/dp-c.png)

- Once the cut has been made, the partitions can be solved independently only if the cuts are sorted. -> We will sort the array.

- To calculate the (cost)length of stick before cut, we will make a little modification. We will add 0 and length of stick after. So that we can do: `cost = cuts[j+1] - cuts[i-1]`

- current ans = (cuts[j+1] - cuts[i-1]) + f(i, idx-1) + f(idx+1, j)
 

## Recursive Solution

```cpp
class Solution {
public:

    int solveCost(vector<int> &cuts, int i, int j, vector<vector<int>> &memo)
    {
        if(i>j)
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int miniCost = INT_MAX;
        for(int idx = i; idx<=j; idx++)
        {
            int cost = (cuts[j+1] - cuts[i-1]) + solveCost(cuts, i, idx-1, memo) + solveCost(cuts, idx+1, j, memo);
            miniCost = min(miniCost, cost);
        }
        return memo[i][j] = miniCost;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> memo(c+2, vector<int>(c+2, -1));

        return solveCost(cuts, 1, cuts.size()-2, memo);
    }
};
```


> Time Complexity - O(n^2), where n-> size of cuts array
> 
> Space Complexity - O(n^2)

## Tabulation Approach

```cpp
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

        for(int i=c;i>=1;i--)
        {
            for(int j=1;j<=c;j++)
            {
                if(i>j)
                    continue;
                else{
                    int miniCost = INT_MAX;
                    for(int idx = i; idx<=j; idx++)
                    {
                        int cost = (cuts[j+1] - cuts[i-1]) + dp[i][idx-1] + dp[idx+1][j];
                        miniCost = min(miniCost, cost);
                    }
                    dp[i][j] = miniCost;
                }
            }
        }

        return dp[1][c];
    }
};
```