# Koko Eating Bananas
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

## Brute Force

- Check each value of k: 0 -> max(piles)
- TC: o(max(piles)) -> TLE

## binary Search

- Binary Search between `1` and `max(piles)`.
- For a `mid` value `k`, calculate total hours needed using `ceil(pile/k)` for each pile.
- If total `hours ≤ h`, update answer and search left.
- Else, search right.

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        
        while(left < right){
            int mid = left + (right-left)/2;

            int hourSpent = 0;

            for(int pile: piles){
                hourSpent += pile/mid + (pile % mid != 0);
            }

            if(hourSpent <= h)
                right = mid;
            else
                left = mid +1;
        }
        return right;
    }
};
```

> Time Complexity: O(logn)
>
> Space Complexity: O(1)
