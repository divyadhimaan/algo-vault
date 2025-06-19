# Power Set

Practice [Link](https://www.geeksforgeeks.org/problems/power-set4302/1#)

Given a string s of length n, find all the possible non-empty subsequences of the string s in lexicographically-sorted order.

## Brute Force Approach

Create every possible subsequence using recursion and backtracking.

```cpp
class Solution{
	public:
	
	    void solve(string s, vector<string> &res, int idx, string f)
	    {
	        if(idx >= s.length())
	        {
	            if(f.length() > 0)
	                res.push_back(f);
	            return;
	        }
	        
	        f += s[idx];
	        
	        solve(s, res, idx+1, f);
	        f.pop_back();
	        solve(s,res,idx+1, f);
	            
	    }
	
		vector<string> AllPossibleStrings(string s){
		    vector<string> res;
		    
		    solve(s, res,0, "");
		    sort(res.begin(), res.end());
		    return res;
		}
};
```

> Time Complexity: `O(2^n) + O(2^n log(2^n))` -> Sorting
>
> Space Complexity: `O(2^n) + O(n)` ->  recursion stack


## Optimal Approach - Trie

```cpp
class TrieNode{
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode(){
        isEnd = false;
        for(int i=0;i<26;i++)
            children[i] = false;
    }
};


class Trie{
public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    bool insert(string word) {
        TrieNode* curr = root;
        
        for(int i=0;i<word.length();i++){
            int idx = word[i]- 'a';
            if(curr->children[idx] == NULL){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        
        curr->isEnd = true;
    }
};

class Solution{
public:
	vector<string> AllPossibleStrings(string s){
	    Trie trie;
        vector<string> res;
        vector<string> prevSubsequences;
        
        for (char ch : s) {
            vector<string> newSubsequences;
            newSubsequences.push_back(string(1, ch));

            for (const string& sub : prevSubsequences) {
                newSubsequences.push_back(sub + ch);
            }

            for (const string& sub : newSubsequences) {
                trie.insert(sub);
                res.push_back(sub);
            }

            prevSubsequences.insert(prevSubsequences.end(), newSubsequences.begin(), newSubsequences.end());
        }
        
        sort(res.begin(), res.end());

        return res;
	}
};
```

> Time Complexity: `O(N^2)`
> 
> - O(N^2) -> Generating subsequences
> - O(N^2) -> trie insertions
> - O(N^2 log N) ->  sorting
