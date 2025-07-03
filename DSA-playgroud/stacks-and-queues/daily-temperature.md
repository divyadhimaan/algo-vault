# Daily Temperature

Practice [Here]()

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


