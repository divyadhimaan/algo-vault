# Binary Tree Level Order Traversal

Practice [here](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)

Given the `root` of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


## Implementation

Visit all nodes at level 0 → then level 1 → then level 2 → …
> Use a queue to process nodes level-by-level, pushing children as you go, so that all nodes at the same depth are visited together.
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root)
            return {};

        vector<vector<int>> traversalResult;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> levelResult;
            for(int i=0;i<size;i++)
            {
                TreeNode* currNode = q.front();
                q.pop();

                levelResult.push_back(currNode->val);

                if(currNode->left)
                    q.push(currNode->left);

                if(currNode->right)
                    q.push(currNode->right);
            }
            traversalResult.push_back(levelResult);
        }
        return traversalResult;
    }
};
```

> Time Complexity: `O(n)`, Each node visited once
>
> Space Complexity: `O(n)`, the queue can store all the nodes of the last level.