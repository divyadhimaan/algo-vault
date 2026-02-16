# Best time to buy and sell stock

Given an array arr of n integers, where arr[i] represents price of the stock on the ith day. Determine the maximum profit achievable by buying and selling the stock at most once.

The stock should be purchased before selling it, and both actions cannot occur on the same day.

## Brute Force

```cpp
class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int maxProfit = INT_MIN;

        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                maxProfit = max(maxProfit, arr[j]-arr[i]);
            }
        }
        return maxProfit > 0 ? maxProfit : 0;
    }
};


```

> Time Complexity: O(n^2) --> TLE
>
> Space Complexity: O(1)

## Optimal Approach

```cpp
class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int maxProfit = INT_MIN;

        int cheapestStock=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i] < cheapestStock)
                cheapestStock = arr[i];

            maxProfit = max(maxProfit, arr[i]-cheapestStock);
        }
        return maxProfit > 0 ? maxProfit : 0;
    }
};


```

> Time Complexity: O(n) 
>
> Space Complexity: O(1)