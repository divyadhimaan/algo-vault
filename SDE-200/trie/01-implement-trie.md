# Implement Trie

Practice [Link](https://leetcode.com/problems/implement-trie-prefix-tree/description/)


A `trie` (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

`Trie()` Initializes the trie object.
`void insert(String word)` Inserts the string `word` into the trie.
`boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
`boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string word that has the prefix `prefix`, and `false` otherwise

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

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i]- 'a';
            if(curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i]- 'a';
            if(curr->children[idx] == NULL)
                return false;
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0;i<prefix.length();i++){
            int idx = prefix[i]- 'a';
            if(curr->children[idx] == NULL)
                return false;
            curr = curr->children[idx];
        }
        return true;
    }
};

```

## Complexities

| Operation        | Time Complexity | Space Complexity |
| -----------------| --------------- | ---------------- |
| Insert           | O(m)            | O(n*m)           |
| Search           | O(m)            | O(1)           |
| PrefixSerarch    | O(m)            | O(1)           |

