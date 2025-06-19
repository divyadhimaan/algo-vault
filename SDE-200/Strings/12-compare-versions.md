# Compare Version Numbers

Practice [Link](https://leetcode.com/problems/compare-version-numbers/description/)


Given two version strings, `version1` and `version2`, compare them. A version string consists of revisions separated by dots `'.'`. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as `0`.

Return the following:

If `version1 < version2`, return` -1`.
If `version1 > version2`, return `1`.
Otherwise, return `0`.

## Brute Force Approach

- Split the versions on '.'
- Compare every revision and decide

```cpp
class Solution {
public:

    vector<int> splitAndConvert(string version) {
        vector<int> result;
        stringstream ss(version);
        string segment;

        while (getline(ss, segment, '.')) {
            result.push_back(stoi(segment)); // convert to int (removes leading 0)
        }

        return result;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = splitAndConvert(version1);
        vector<int> v2 = splitAndConvert(version2);


        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i) {
            int num1 = i < v1.size() ? v1[i] : 0;
            int num2 = i < v2.size() ? v2[i] : 0;
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        return 0;
    }
};
```

> Time Complexity: O(N + M), where N and M are lengths of version1 and version2 respectively.
>
>Space Complexity: O(N + M)

> NOTE - This is efficient enough but can be improved in space.

## Optimal




- No need to store full vectors.
- Parse and compare on-the-fly using two pointers.


```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m =version1.size(), n = version2.size();

        for(int i=0,j=0; (i<m)||(j<n); i++,j++)
        {
            int val1 =0, val2 = 0;
            while((i<m) && version1[i]!='.')
                val1 = val1*10 + (version1[i++]-'0');
            while((j<n) && version2[j]!='.')
                val2 = val2*10 + (version2[j++]-'0');

            if(val1 <val2)
                return -1;
            else if(val1 > val2)
                return 1;
        }
        return 0;
    }
};
```


> Time Complexity: O(N + M), where N and M are lengths of version1 and version2 respectively.
>
> Space COmplexity: O(1)



## Summary 
| Approach    | Time Complexity | Space Complexity | Comments                     |
| ----------- | --------------- | ---------------- | ---------------------------- |
| Brute-force | O(N + M)        | O(N + M)         | Stores split vectors         |
| Optimized   | O(N + M)        | O(1)             | Parses and compares directly |

