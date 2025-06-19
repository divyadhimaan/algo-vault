# All Nodes Distance K in Binary Tree

Practice [Link](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/)

Given the `root` of a binary tree, the value of a target node `target`, and an integer `k`, return an array of the values of all nodes that have a distance `k` from the target node.

You can return the answer in any order.

## Approach

The problem is solved by transforming the binary tree into an undirected graph, allowing traversal in both upward (parent) and downward (child) directions.

- Build the Graph:
  - Use DFS to create an adjacency list from the binary tree.
  - For every node, connect it bidirectionally with its left and right children.
- DFS Traversal from Target:
  - Perform DFS starting from the target node.
  - Use a visited set to avoid revisiting nodes.
  - At each recursive call, reduce the distance k by 1.
  When `k == 0`, collect the current node in the result list.

## Implementation

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void buildGraph(TreeNode* root, unordered_map<int,vector<int>>&graph)
    {
        if(!root)
            return;
        
        //link left child
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left, graph);
        }
        
        //link right child
        if(root->right)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right, graph);
        }

        //also add leaf nodes
        if (graph.find(root->val) == graph.end()) {
            graph[root->val] = {};
        }
    }

    void dfsDistanceK(unordered_map<int,vector<int>> &graph, int k, int node, vector<int> &result, vector<bool> &visited)
    {
        if(k==0){
            result.push_back(node);
            return;
        }

        visited[node] = true;

        for(int nextNode: graph[node])
        {
            if(!visited[nextNode] && k)
                dfsDistanceK(graph, k-1, nextNode, result, visited);
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> graph;
        buildGraph(root, graph);

        //edge cases
        if(k==0)
            return {target->val};

        vector<int> result;
        vector<bool> visited(graph.size(), false);
        dfsDistanceK(graph, k, target->val, result, visited);
        
        return result;
    }
    
};
```

> Time Complexity: O(n)
> 
> Space Complexity: O(n)