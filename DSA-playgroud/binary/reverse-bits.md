# Reverse Bits


## Brute Force
```cpp
class Solution {
public:
    int reverseBits(int n) {
        if (n==0)
            return 0;
        string bit;
        while (n>0) {
            bit = (n % 2 ==0 ? "0" : "1") + bit;
            n /= 2;
        }
        while (bit.length()<32)
        {
            bit = "0"+bit;
        }
        reverse(bit.begin(),bit.end());
        int num = stoi(bit, nullptr, 2);
        return num;
    }
};
```

## Bit Manipulation

```cpp
class Solution {
public:
    int reverseBits(int n) {
        uint32_t res = 0;

        for(int i=0;i<32;i++)
        {
            res = res << 1;
            res = res | (n&1);
            n = n >> 1;
        }
        return res;
    }
};
```

> Time Complexity: O(32) ~ O(1)  
>
> Space Complexity: O(1)