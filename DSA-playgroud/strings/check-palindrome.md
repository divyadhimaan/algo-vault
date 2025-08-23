# Palindrome Number

Practice [here](https://leetcode.com/problems/palindrome-number/description/)

Given an integer `x`, return `true` if x is a palindrome, and `false` otherwise.

## Brute Force: Converting to String
```cpp
class Solution {
public:
    bool checkPalindrome(string s)
    {
        cout<<"str in second level: "<<s<<endl;

        int n = s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }

    bool isPalindrome(int x) {
        string str = to_string(x);
        bool isNeg = str[0]=='-';
        return isNeg ? false : checkPalindrome(str);
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)


## Better Approach
1. If x is negative or ends in a 0 (and is not 0 itself), return false.
2. Reverse the digits of the second half of the number until it’s greater than or equal to the remaining first half.
   - Use revHalf to store the reversed second half.
   - On each iteration, shift one digit from x to revHalf.
3. After the loop:
   - If x == revHalf, it's a palindrome with even length.
   - If x == revHalf / 10, it’s a palindrome with odd length (middle digit doesn’t affect symmetry).

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int revHalf = 0;
        while (x > revHalf) {
            int digit = x % 10;
            revHalf = revHalf * 10 + digit;
            x /= 10;
        }

        
        return (x == revHalf || x == revHalf / 10);
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)