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
> Space Complexity: O(n)

## XOR approach