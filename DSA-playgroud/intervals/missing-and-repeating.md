# Missing and Repeating Number


## Brute Force Approach

Sort the array and scan.

> Time Complexity: O(n log n)
>
> Space Complexity: O(1)

## Better Approach
```cpp
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        vector<int> hash(nums.size()+1, 0);

        int missing=-1, repeating;
        for(int i=0;i<nums.size();i++)
        {
            if(hash[nums[i]]!= 0)
                repeating=nums[i];
            hash[nums[i]]++;
        }

        for(int i=0;i<hash.size();i++)
            if(hash[i]==0)
                missing = i;

        return {repeating, missing};
    }
};
```

> Time Complexity: O(n) -> Two traversal
>
> Space Complexity: O(n)


## Maths Approach

1. **Expected Sum and Sum of Squares**
   - Sum of first `n` numbers:
     ```
     Sn = n * (n + 1) / 2
     ```
   - Sum of squares of first `n` numbers:
     ```
     Sn2 = n * (n + 1) * (2n + 1) / 6
     ```

2. **Compute Differences**
   - Let:
     ```
     S  = sum of array elements
     S2 = sum of squares of array elements
     ```
   - Then:
     ```
     x - y = S  - Sn
     x² - y² = S2 - Sn2
     ```

3. **Form Linear Equations**
   - Use the identity:
     ```
     x² - y² = (x - y) * (x + y)
     ```
   - Compute:
     ```
     x + y = (x² - y²) / (x - y)
     ```

4. **Solve for x and y**


### Implementation
```cpp
class Solution {
public:
    vector<int> solveTwoLinearEquations(int diff, int sum)
    {
        // y = (x+y)/(2*(x-y));
        long long y = (sum-diff)/2;
        long long x = diff+y;
        return {(int)x,(int)y};
    }

    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        // assume 
        // x->repeating number
        // y->missing number
        int n = nums.size();

        // equation 1: S - Sn = x - y
        // equation 2: (S)^2 - (Sn)^2 = (x)2 - (y)2
        long long Sn = 1LL * n * (n+1)/2;
        long long Sn2 = 1LL * n * (n+1) * ((2*n)+1)/6;

        long long S = 0;
        long long S2 = 0;
        for(int num: nums){
            S += num;
            S2 += 1LL * num*num;
        }

        
        long long x_minus_y = S - Sn; //x - y
        long long x2_minus_y2 = S2 - Sn2; // x^2 - y^2
        long long x_plus_y = x2_minus_y2 / x_minus_y; //x + y

        return solveTwoLinearEquations(x_minus_y, x_plus_y); 

    }
};
```
> Time Complexity: O(n)
>
> Space Complexity: O(1)

## XOR approach

1. XOR cancel duplicates because
```
x ^ x = 0
x ^ 0 = x
```
2. If we XOR all elements of the array and all numbers from 1 to n, all pairs will cancel out, leaving:
```xr = Missing ^ Repeating```
3. Since the two numbers are different, there will be at least one bit where they differ.
   - Use that rightmost set bit to separate the numbers into two groups.
   - Each group contains numbers contributing to either missing or repeating.
4. After XORing separately, we get two candidates → determine which one is repeating by checking array.


```cpp
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        //find XOR(all ele of nums and all numbers 1 to n)
        int xr = 0;
        for(int i=0;i<nums.size();i++)
        {
            xr ^= nums[i];
            xr ^= i+1;
        }

        // find rightmost differentiating bit
        int bitNo = 0;
        while(1){
            if((xr & (1<< bitNo)) != 0)
                break;
            bitNo++;
        }

        //seperate all ele and numbers 1 to n into group of zero and one based on the bitNo
        int one =0;
        int zero=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] & (1<<bitNo))
                one ^= nums[i];
            else
                zero ^= nums[i];

            if(i+1 & (1<<bitNo))
                one ^= i+1;
            else    
                zero ^= i+1;
        }

        int isOneRepeating = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==one)
                isOneRepeating = true;
        }

        if(isOneRepeating)
            return {one, zero};
        return {zero, one};
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)

## Summary

| Approach        | Time       | Space | Overflow Risk       | Modifies Array   | Simplicity  |
| --------------- | ---------- | ----- | ------------------- | ---------------- | ----------- |
| **Brute Force** | O(n log n) | O(1)  | No                  | Yes (if sorting) | Easy        |
| **Hashing**     | O(n)       | O(n)  | No                  | No               | Easy        |
| **Math**        | O(n)       | O(1)  | Yes (use long long) | No               | Medium      |
| **XOR**         | O(n)       | O(1)  | No                  | No               | Medium-Hard |
