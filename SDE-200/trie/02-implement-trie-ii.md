# Implement Trie - II

Practice [Link](https://www.naukri.com/code360/problems/implement-trie_1387095)


Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.
1) `Trie()`: Ninja has to initialize the object of this “TRIE” data structure.

2) `insert(“WORD”)`: Ninja has to insert the string “WORD”  into this “TRIE” data structure.

3) `countWordsEqualTo(“WORD”)`: Ninja has to return how many times this “WORD” is present in this “TRIE”.

4) `countWordsStartingWith(“PREFIX”)`: Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5) `erase(“WORD”)`: Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.
Note:
   1. If `erase(“WORD”)` function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

   2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.
Can you help Ninja implement the "TRIE" data structure?


## Implementation

```cpp
#include <bits/stdc++.h> 

class TrieNode{
    public:
        TrieNode* children[26];
        int wordCount;
        int prefixCount;

        TrieNode(){
            wordCount = 0;
            prefixCount = 0;
            for(int i=0;i<26;i++)
            {
                children[i] = NULL;
            }
        }
};
class Trie{

    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
       TrieNode* curr = root;
       for(int i=0;i<word.length();i++)
       {
           int idx = word[i] - 'a';
           if(!curr->children[idx])
                curr->children[idx] = new TrieNode();
            curr =curr->children[idx];
            curr->prefixCount++;
       }
       curr->wordCount++;
    }

    int countWordsEqualTo(string &word){
        TrieNode* curr = root;
       for(int i=0;i<word.length();i++)
       {
           int idx = word[i] - 'a';
           if(!curr->children[idx])
                return 0;
            curr =curr->children[idx];
       }
       return curr->wordCount;
    }

    int countWordsStartingWith(string &word){
        TrieNode* curr = root;
       for(int i=0;i<word.length();i++)
       {
           int idx = word[i] - 'a';
           if(!curr->children[idx])
                return 0;
            curr =curr->children[idx];
       }
       return curr->prefixCount;
       
    }

    void erase(string &word){
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++)
       {
           int idx = word[i] - 'a';
           if (curr->children[idx]) {
                curr = curr->children[idx];
                curr->prefixCount--;
           }else
                return;
       }
       curr->wordCount--;
    }
};


```

## Complexities

| Operation        | Time Complexity | Space Complexity |
| -----------------| --------------- | ---------------- |
| Insert a word           | O(N)            | O(N*M)           |
| Count words equal to a word           | O(N)            | O(1)           |
| Count words starting with a prefix    | O(N)            | O(1)           |
| Erase a word | O(N) | O(1) (without cleanup), O(N) (with cleanup)|

