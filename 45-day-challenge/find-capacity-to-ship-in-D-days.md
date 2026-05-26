# Capacity To Ship Packages Within D Days

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 
## Intuition
You're not searching an index — you're searching an answer

- You’re trying to find a number (capacity), not a position in the array.

- So instead of:
  - searching where something is
  - you’re searching what value works
- If a ship capacity = X works (i.e., you can ship within days), then:

- Any capacity > X will also work
- Any capacity < X might fail

👉 This gives a monotonic search space: Therefore binary search.

## Search Space

- Minimum load allowed -> max weight of parcel (atleast one needs to be shipped)
- Maximum load allowed -> sum of all parcels (deliver everything in one day)

## Binary Search solution

```cpp
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()), right = 0;

        for(int w:weights)
            right += w;
        
        while(left < right){
            int midWeight = left + (right-left)/2;

            int daysTaken = 1, currWeight=0;

            for(int weight: weights){
                if(currWeight + weight > midWeight){
                    daysTaken++;
                    currWeight = 0;
                }
                currWeight += weight;
            }

            if(daysTaken <= days)
                right = midWeight;
            else
                left = midWeight +1;
        }
        return left;
    }
};
```

> Time Complexity: O(logn)
> 
> Space Complexity: O(1)

## Enhancement

```cpp
class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity){
        int daysTaken = 1, currWeight=0;

        for(int weight: weights){
            if(currWeight + weight > capacity){
                daysTaken++;
                currWeight = 0;
            }
            currWeight += weight;
        }
        return daysTaken <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()), right = 0;

        for(int w:weights)
            right += w;
        
        while(left < right){
            int midWeight = left + (right-left)/2;

            bool canShipParcel = canShip(weights, days, midWeight);

            if(canShipParcel)
                right = midWeight;
            else
                left = midWeight +1;
        }
        return left;
    }
};
```

- Structurally clean code