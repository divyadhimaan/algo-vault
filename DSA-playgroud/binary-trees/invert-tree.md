# Invert Binary Tree

Practice [here](https://leetcode.com/problems/invert-binary-tree/description/)

Given the `root` of a binary tree, invert the tree, and return its `root`.


## Recursion Approach
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

    void invertTreeUtil(TreeNode* root)
    {
        if(!root)
            return;
        if(root->left || root->right)
            swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        invertTreeUtil(root);
        return root;
    }
};
```

> Time Complexity: `O(n)`, Each node visited once
>
> Space Complexity: `O(h)`, Recursion stack

## Iterative Approach

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* currNode = q.front();
            q.pop();

            if(currNode->left || currNode->right)
                swap(currNode->left, currNode->right);

            if(currNode->left)
                q.push(currNode->left);

            if(currNode->right)
                q.push(currNode->right);
        }

        return root;
    }
};
```

> Time Complexity: `O(n)`, Each node visited once
>
> Space Complexity: `O(n)`, the queue can store all the nodes of the last level.