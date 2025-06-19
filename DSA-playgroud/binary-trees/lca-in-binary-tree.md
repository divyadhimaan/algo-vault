# Lowest Common Ancestor of a Binary Tree

Practice [Link](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)


Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)
            return root;

        TreeNode* leftNode = lowestCommonAncestor(root->left, p,q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p,q);

        if(!leftNode)   
            return rightNode;
        if(!rightNode)
            return leftNode;

        return root;
    }
};
```