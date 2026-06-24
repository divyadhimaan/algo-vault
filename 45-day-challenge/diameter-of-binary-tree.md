# Diameter of Binary Tree

**Problem:** [LeetCode 543](https://leetcode.com/problems/diameter-of-binary-tree/)  
**Difficulty:** Easy  
**Topic:** Binary Tree, DFS

## Problem Summary

Given the root of a binary tree, return the length of the **diameter** — the longest path between any two nodes. The path may or may not pass through the root. Length is measured in number of edges.

## Approach: DFS with Height Tracking

At every node, the diameter through it equals `left_height + right_height`. We compute heights bottom-up via DFS, and track the running maximum across all nodes.

**Key insight:** the function returns height (for the parent's use), but updates `maxi` as a side effect on the way back up.

## Solution

```cpp
class Solution {
public:
    int findMaxi(TreeNode* root, int &maxi) {
        if (!root) return 0;

        int left  = findMaxi(root->left,  maxi);
        int right = findMaxi(root->right, maxi);

        maxi = max(maxi, left + right);   // diameter through this node

        return 1 + max(left, right);       // height of this node
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxi(root, maxi);
        return maxi;
    }
};
```

## Complexity

|       |                                         |
|-------|-----------------------------------------|
| Time  | O(n) — each node visited once           |
| Space | O(h) — recursion stack, h = tree height |

## Notes

- `maxi` is passed by reference so updates propagate up without a global variable.
- For a single-node tree, `left + right = 0`, so `maxi = 0` — correct.
- `INT_MIN` is safe here since the minimum possible diameter is 0, which will always overwrite it.
