# Maximum Depth of Binary Tree

Practice [here](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)

Given the `root` of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


## Recursive Approach


`Analogy`: It’s like standing on a floor and saying:
“I don’t know how many floors there are below me… let me ask the left staircase and the right staircase. Whichever says more floors, I’ll trust that and add mine.”

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};
```
> Time Complexity: `O(n)`, Each node visited once
>
> Space Complexity: `O(h)`, Recursion stack,
> - Worst Case: O(h) = O(n), Skewed tree
> - Best case: O(h) = O(logn), Balanced tree



## Iterative Approach

`Analogy`: Let’s explore the building floor by floor, moving everyone on the current floor to the next floor all together.
Each time we finish a floor, we increase the floor count.

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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while(!q.empty())
        {
            
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* currNode = q.front();
                q.pop();

                if(currNode->left)
                    q.push(currNode->left);
                if(currNode->right)
                    q.push(currNode->right);
            }
            depth++;
        }
        return depth;
    }
};
```

> Time Complexity: `O(n)`, Each node visited once
>
> Space Complexity: `O(n)`
> - Worst Case: In the worst case, the queue can store all the nodes of the last level.
