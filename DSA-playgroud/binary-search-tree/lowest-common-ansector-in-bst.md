# Lowest Common Ancestor of a Binary Search Tree

Practice [here](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

## Implementation
Treat it as a normal binary tree (not using BST properties).
- Recurse left and right.
- If both left and right return non-null → current node is LCA.
- Otherwise, propagate the non-null one upward.
  
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(!left)
            return right;
        if(!right)
            return left;
        return root;
    }
};
```


## Optimal Approach


Use BST ordering to skip unnecessary searches:
- If both p and q are smaller than root → LCA lies in left subtree.
- If both are larger than root → LCA lies in right subtree.
- If they diverge across root (one smaller, one larger) → root is LCA.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)
            return root;

        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
```