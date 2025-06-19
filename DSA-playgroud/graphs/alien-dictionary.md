# Alien Dictionary


Given a `sorted` dictionary of an alien language having some words `dict` and `k` starting alphabets of a standard dictionary. Find the `order` of characters in the alien language. If no valid ordering of letters is possible, then return an empty string.

Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be "true" if the order of string returned by the function is correct else "false" denotes incorrect string returned.


Practice [Link](https://www.geeksforgeeks.org/problems/alien-dictionary/1)

## Sample
> Input: dict[] = ["baa","abcd","abca","cab","cad"], k = 4
> Output: true
> Explanation: order -> b, d, a, c

## Intiution
We need to find the order of characters, which comes before which character. Sounds like a topological sort. 
Hard part is to create the directed graph from the dictionary given.
Hint: Consider two consecutive words in a dictionary, and decide why the first one comes before the latter (compare the differentiating character among the two words).


## Approach
* Creating AdjList 
  * Loop though the dictionary and pick two consecutive words at a time. 
  * Out of two words, find the differentiating character (lets say at diffIdx).
    * wordA[diffIdx] -> wordB[diffIdx]
  * Also store the inDegrees of the characters.
* Do standard topological sort and store the order of characters.


## Implementation
```cpp

void createAdjListAndIndegree(vector<string> dict, vector<vector<int>> &adj, vector<int> &inDegree)
    {
        int size = dict.size();
        for(int i=0;i<size-1;i++)
        {
            string wordA = dict[i];
            string wordB = dict[i+1];
            
            int minSize = min(wordA.length(), wordB.length());
            
            for(int i=0;i<minSize;i++)
            {
                if(wordA[i] != wordB[i])
                {
                    adj[wordA[i] - 'a'].push_back(wordB[i] - 'a');
                    inDegree[wordB[i] - 'a']++;
                    break;
                }
                    
            }
            
        }
        
    }
  
    string findOrder(vector<string> dict, int k) {
        vector<vector<int>> adj(k);
        vector<int> inDegree(k);
        
        createAdjListAndIndegree(dict, adj, inDegree);
        
        queue<int> q;
        string result="";
        
        for(int i=0;i<k;i++)
        {
            if(inDegree[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int topChar = q.front();
            q.pop();
            for(auto nextChar: adj[topChar])
            {
                inDegree[nextChar]--;
                if(inDegree[nextChar]==0)
                    q.push(nextChar);
            }
            result+=topChar+'a';
        }
        
        
        return result;
    }
```

