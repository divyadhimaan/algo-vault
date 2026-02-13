# 


```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freqMap;

        for(int num: nums){
            freqMap[num]++;
        }

        int n = nums.size();
        for(auto x: freqMap){
            if(x.second > n/2)
                return x.first;
        }
        return -1;
    }
};
```
> Time Complexity: O(n)
>
> Space Complexity: O(n)

## Optimal Approach

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityEle, freq = 0;

        for(int num: nums){
            if(freq == 0){
                majorityEle = num;
                freq=1;
            } else if(majorityEle == num){
                freq++;
            }else{
                freq--;
            }
        }

        return majorityEle;
    }
};
```
> Time Complexity: O(n)
>
> Space Complexity: O(1)