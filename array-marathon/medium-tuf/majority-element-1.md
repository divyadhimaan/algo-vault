e# 


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

## Optimal Approach: Boyer-Moore Voting Algorithm

**Intuition:** if the majority element appears more than n/2 times, it outnumbers all other elements combined. Pair up every majority occurrence with a non-majority one — even after all cancellations, the majority element survives.

**How it works:** maintain a `candidate` and a `freq` counter.
- When `freq == 0`, the current element becomes the new candidate.
- If the current element matches the candidate, increment `freq` (vote for it).
- If it doesn't match, decrement `freq` (cancel one vote out).

Every mismatch cancels one candidate vote with one opposing vote. Since the majority element has more votes than all others combined, it always ends up as the last candidate standing.

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