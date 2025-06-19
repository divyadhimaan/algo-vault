# Online Stock Span

Practice [Link](https://leetcode.com/problems/online-stock-span/description/)

Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.


Implement the `StockSpanner` class:

`StockSpanner()` Initializes the object of the class.
`int next(int price)` Returns the span of the stock's price given that today's price is `price`.

```cpp
class StockSpanner {
public:
    stack<pair<int,int>> stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while(!stk.empty() && stk.top().first <= price)
        {
            ans += stk.top().second;
            stk.pop();
        }
        stk.push({price, ans});
        return ans;
    }
};
```

