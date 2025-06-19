# Reverse Words in a String

Practice [Link](https://leetcode.com/problems/reverse-words-in-a-string/description/)


Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.


## Implementation

### Stack Approach

```cpp
class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;

        string temp="";
        for(char c: s)
        {
            if(c==' ' && temp!=""){
                stk.push(temp);
                temp="";
            }
            else if(c!=' '){
                temp += c;
            }
        }
        if(temp!="")
            stk.push(temp);

        string ans="";
        while(!stk.empty()){
            ans += stk.top() + " ";
            stk.pop();
        }
        ans.pop_back();
        return ans;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(w), w -> number of words


### Two pointer Approach

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int left = 0, right = n-1;


        while (left < n && s[left] == ' ') left++; //skip any leading spaces
        while (right >= 0 && s[right] == ' ') right--; //skip any trailing spaces

        string temp = "", ans="";

        while(left<=right)
        {
            char ch = s[left];
            if(ch!=' ')
                temp += ch;
            else{
                if(ans!="")
                    ans = temp + " " + ans;
                else
                    ans = temp;
                temp="";
                while (left + 1 <= right && s[left + 1] == ' ') left++; // skip any extra spaces
            }

            left++;
        }
        if(temp!="")
        {
            if(ans!="")
                    ans = temp + " " + ans;
            else
                ans = temp;
        }
        return ans;
    }
};
```

> Time Complexity: O(n)
>
> Space Complexity: O(1)