# String to Integer (atoi)

Practice [Link](https://leetcode.com/problems/string-to-integer-atoi/description/)

```cpp
class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0)
            return 0;


        //ignore trailing whitespaces
        int start =0;
        while (start < s.length() && s[start] == ' ')
            start++;

        //check sign
        int sign = 1;
        if (start < s.length() && (s[start] == '+' || s[start] == '-')) {
            if (s[start] == '-') sign = -1;
            start++;
        }


        //ignore trailing zereos
        while (start < s.length() && s[start] == '0')
            start++;

        int ind = start;
        while(ind<s.length() && s[ind]>='0' && s[ind]<='9')
            ind++;

        if(start==ind)
            return 0;

        long long num=0;
        for(int i=start;i<ind;i++)
        {
            int digit = s[i]-'0';
            num = num*10 + digit;
            if(sign==-1 && -num < INT32_MIN)
                return INT32_MIN;
            if(sign == 1 && num > INT32_MAX)
                return INT32_MAX;
        }

        return (sign)*num;
    }
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(1)