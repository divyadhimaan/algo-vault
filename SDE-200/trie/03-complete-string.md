# Complete String

Practice [Link](https://www.naukri.com/code360/problems/complete-string_2687860)

Ninja developed a love for arrays and strings so this time his teacher gave him an array of strings, ‘A’ of size ‘N’. Each element of this array is a string. The teacher taught Ninja about prefixes in the past, so he wants to test his knowledge.
A string is called a complete string if every prefix of this string is also present in the array ‘A’. Ninja is challenged to find the longest complete string in the array ‘A’.If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".
Note :
String ‘P’ is lexicographically smaller than string ‘Q’, if : 

1. There exists some index ‘i’ such that for all ‘j’ < ‘i’ , ‘P[j] = Q[j]’ and ‘P[i] < Q[i]’. E.g. “ninja” < “noder”.

2. If ‘P’ is a prefix of string ‘Q’, e.g. “code” < “coder”.

```cpp

class TrieNode{
    public:
        bool isEnd;
        TrieNode* children[26];

        TrieNode(){
            isEnd = false;
            for(int i=0;i<26;i++)
                children[i] = NULL;
        }
};
class Trie{
    public:
        TrieNode* root;
        Trie()
        {
            root= new TrieNode();
        }

        void insert(string word)
        {
            TrieNode* curr = root;
            for(int i=0;i<word.length();i++)
            {
                int idx = word[i] -'a';
                if(curr->children[idx] == NULL)
                    curr->children[idx] = new TrieNode();
                curr = curr->children[idx];
            }
            curr->isEnd = true;
        }

        bool checkPrefix(string word)
        {
            TrieNode* curr = root;
            for(int i=0;i<word.length();i++)
            {
                int idx = word[i] -'a';
                if (curr->children[idx] != NULL) {
                    curr = curr->children[idx];
                    if (!curr->isEnd)
                      return false;
                }else
                    return false;
            }
            return true;
        }
};

string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto i: a)
        trie.insert(i);

    string ans="";
    for(auto x: a)
    {
        if(trie.checkPrefix(x)){
            if(x.length() > ans.length())
                ans = x;
            else if(x.length() == ans.length() && x < ans)
                ans = x;
        }
    }

    if(ans.size()==0)
        return "None";
    return ans;
}
```

> Time Complexity: O(nL)
>
> Space Complexity: O(nL), where n is number of words, L is the maximum length of any word in a