# Binary Tree Zigzag Level Order Traversal

Practice [here](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)

Given the `root` of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).


## Implementation
Visit all nodes at level 0 → then level 1 → then level 2 → …
> Perform normal level-order traversal using a queue, but reverse the order of values every alternate level to simulate the zig-zag pattern.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};

        vector<vector<int>> traversalResult;
        queue<TreeNode*> q;
        q.push(root);

        int levelId = 0;

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
            if(levelId%2!=0){
                reverse(levelResult.begin(), levelResult.end());
                traversalResult.push_back(levelResult);
            }
            else
                traversalResult.push_back(levelResult);

            levelId++;
        }
        return traversalResult;
    }
};
```

> Time Complexity: `O(n)`, Each node visited once
>
> Space Complexity: `O(n)`, the queue can store all the nodes of the last level.