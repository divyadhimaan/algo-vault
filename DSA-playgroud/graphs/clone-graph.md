# Clone Graph

Practice [Here](https://leetcode.com/problems/clone-graph/description/)

Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.


## Solution

- Use a map to store new old node to new node mapping
- While traversing(BFS), creating the new graph too.

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        //old node - new node mapping
        unordered_map<Node*, Node*> mp;

        if(!node)
            return NULL;

        Node* first = new Node(node->val, {});
        mp[node] = first;

        queue<Node*> q;
        q.push(node);

        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();

            for(auto next: curr->neighbors)
            {
                if(mp.find(next) == mp.end())
                {
                    mp[next] = new Node(next->val, {});
                    q.push(next);
                }
                mp[curr]->neighbors.push_back(mp[next]);
            }
        }
        return mp[node];
        
    }
};
```