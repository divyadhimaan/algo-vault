# Daily Temperature

Practice [Here]()

## Stack Approach

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;

        vector<int> res(n, 0);

        for(int i = n-1; i>=0;i--){
            if(stk.empty()){
                stk.push(i);
                res[i] = 0;
            }else{
                while(!stk.empty() && temperatures[i] >= temperatures[stk.top()]){
                    stk.pop();
                }

                if(stk.empty()){
                    res[i] = 0;
                }else{
                    res[i] = stk.top() - i;
                }

                stk.push(i);
            }
        }
        return res;
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(n)

## Deque Approach
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        deque<int> dq;

        vector<int> res(temperatures.size());

        for(int i=temperatures.size()-1;i>=0;i--)
        {
            if(dq.empty())
            {
                dq.push_front(i);
                res[i]=0;
            }else{
                while(!dq.empty() && temperatures[i] >= temperatures[dq.front()])
                {
                    dq.pop_front();
                }

                if(dq.empty())
                    res[i]=0;
                else
                    res[i] = dq.front()-i;
                dq.push_front(i);
            }
            
        }
        return res;
    }
};
```

> Underlying Stack uses dequeue implementation.
> We only need one side operation -> stack can be used
