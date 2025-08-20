# Subtree of Another Tree

Practice [here](https://leetcode.com/problems/subtree-of-another-tree/description/)

Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values of `subRoot` and `false` otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

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
    bool checkIdentical(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;

        return root1->val == root2->val && checkIdentical(root1->left, root2->left) && checkIdentical(root1->right, root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;

        if(checkIdentical(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
```

> Time Complexity:` O(n × m)`, 
> - In the worst case, for every node in the main tree (n nodes), you may need to call checkIdentical and compare it with the subRoot (which takes up to m time).
>
> Space Complexity: `O(h)`
> - You are using recursive DFS in both isSubtree() and checkIdentical(), so the maximum depth of the recursion stack is the height of the tree → h.

