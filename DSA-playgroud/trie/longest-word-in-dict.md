# Longest Word in Dictionary

Practice [here](https://leetcode.com/problems/longest-word-in-dictionary/)

## Set Approach 
```cpp
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> st;

        string res="";

        for(string word: words)
        {
            int len = word.length();
            if(len==1 || st.count(word.substr(0, len-1))){
                if(len > res.length())
                    res = word;
                st.insert(word);
            }

        }
        return res;
    }
};
```

> Time Complexity: `O(nlogn + nL)`, n -> total words in dict, L -> is the average word length.
> - O(N log N) — for sorting the words.
> - O(N * L) — for checking prefix and inserting into the set, where L is the average word length.
> 
> Space Complexity: `O(nL)`


## Trie Based
```cpp
class TrieNode{
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode()
    {
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isEnd = false;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode* curr = root;

        for(int i=0;i<word.length();i++)
        {
            int idx = word[i]-'a';
            if(curr->children[idx]==NULL)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    void solve(TrieNode* curr, string &ans, string temp)
    {
        if(curr->isEnd)
        {
            if(ans=="" || ans.size()<temp.size())
                ans=temp;
            else if(ans.size()==temp.size())
                if(ans>temp)
                    ans=temp;
        
        }
        for(char ch='a'; ch<='z';ch++)
        {
            if(curr->children[ch-'a']!= NULL)
            {
                TrieNode* next = curr->children[ch-'a'];
                if(next->isEnd)
                {
                    temp.push_back(ch);
                    solve(next, ans, temp);
                    temp.pop_back();
                }
            }

        }
    }
     
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        int n = words.size();
        Trie* t = new Trie();
        for(int i=0;i<n;i++)
        {
            t->insert(words[i]);
        }

        string ans = "";
        t->solve(t->root, ans, "");
        return ans;
    }
};
```


> Time Complexity: `O(nL) + O(26*L)`, n -> total words in dict, L -> is the average word length.
> - Building Trie: O(N * L), where N is the number of words and L is the average word length.
> - DFS traversal: O(26 * max depth) ≈ O(26 * L)
> 
> Space Complexity: `O(nL)`