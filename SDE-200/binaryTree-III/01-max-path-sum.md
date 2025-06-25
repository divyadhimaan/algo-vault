# Binary Tree Maximum Path Sum

Practice [here](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return the maximum path sum of any non-empty path.

```cpp
class Solution {
public:
    int maxPathSumUtil(TreeNode* root, int &maxi) {
        if(!root)
            return 0;
        
        int leftSum = max(0, maxPathSumUtil(root->left, maxi));
        int rightSum = max(0, maxPathSumUtil(root->right, maxi));

        maxi = max(maxi, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathSumUtil(root, maxi);
        return maxi;
    }
};
```

> Time Complexity: O(N)
>
> Space Complexity: O(H) where H is the height of the binary tree (worst-case O(N))