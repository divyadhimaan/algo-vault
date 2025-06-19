# Count Distinct Substrings

Practice [Link](https://www.naukri.com/code360/problems/count-distinct-substrings_985292)

Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.



## Using Trie
```cpp
class TrieNode {
public:
    TrieNode* children[26];
    TrieNode(){
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }

};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
 
    int insert(string& str){
        int newNode=0;
        TrieNode* curr=root;
        for(char ch: str){
            int idx=ch-'a';
            if(curr->children[idx]==nullptr){
                curr->children[idx]=new TrieNode();
                newNode++;
            }
            curr=curr->children[idx];
        }
        return newNode;
 
    }
};

int countDistinctSubstrings(string &s)
{
    Trie trie;
    int count =0;
    for(int i=0;i<s.size();i++)
    {
        string suffix = s.substr(i);
        count += trie.insert(suffix);
    }
    return count+1;
}
```

> Time Complexity: O(n^2)
>
> Space Complexity: O(n^2)