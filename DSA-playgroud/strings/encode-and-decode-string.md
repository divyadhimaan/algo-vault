# Encode and Decode a String
Given an array of strings `s[]`, you are required to create an algorithm in the `encode()` function that can convert the given strings into a single encoded string, which can be transmitted over the network and then decoded back into the original array of strings. The decoding will happen in the `decode()` function.

You need to implement two functions:
1. `encode()`: This takes an array of strings s[] and encodes it into a single string. 
2. `decode()`: This takes the encoded string as input and returns an array of strings containing the original array as given in the encode method.


## Implementation
```cpp
class Solution {
  public:
    string encode(vector<string>& s) {
        string encodedString="";
        for(int i=0;i<s.size();i++){
            encodedString += s[i] + '#';
        }
        return encodedString;
    }

    vector<string> decode(string& s) {
        vector<string> decodedList;
        string tempStr = "";
        for(char c: s)
        {
            if(c=='#'){
                decodedList.push_back(tempStr);
                tempStr = "";
                continue;
            }
            tempStr += c;
        }
        return decodedList;
    }
};
```

> Time Complexity:
>   - Encode: O(n)
> - Decode: O(n)