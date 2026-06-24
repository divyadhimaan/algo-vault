# Diameter of Binary Tree

**Problem:** [LeetCode 543](https://leetcode.com/problems/diameter-of-binary-tree/)  
**Difficulty:** Easy  
**Topic:** Binary Tree, DFS

## Problem Summary

Given the root of a binary tree, return the length of the **diameter** — the longest path between any two nodes. The path may or may not pass through the root. Length is measured in number of edges.

---

## Approach 1: DFS with Height Tracking (Optimal)

At every node, the diameter through it equals `left_height + right_height`. Compute heights bottom-up via DFS, tracking the running maximum across all nodes.

**Key insight:** the function returns height (for the parent's use), but updates `maxi` as a side effect on the way back up — dual purpose in one pass.

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

**Complexity:** Time O(n), Space O(h)

---

## Approach 2: Naive DFS (Two Separate Functions)

For each node, compute left height + right height separately, then recurse on children. Simpler to reason about but recomputes heights repeatedly.

```cpp
class Solution {
    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int through_root = height(root->left) + height(root->right);
        int left_subtree  = diameterOfBinaryTree(root->left);
        int right_subtree = diameterOfBinaryTree(root->right);

        return max(through_root, max(left_subtree, right_subtree));
    }
};
```

**Problem:** `height()` is called redundantly at every node → O(n²) time.

**Complexity:** Time O(n²), Space O(h)

---

## Approach 3: DFS with Class-Level Variable

Same as Approach 1 but stores `maxi` as a class member instead of passing by reference. Marginally cleaner call signature.

```cpp
class Solution {
    int maxi = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left  = dfs(root->left);
        int right = dfs(root->right);

        maxi = max(maxi, left + right);

        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};
```

**Note:** initializing `maxi = 0` (not `INT_MIN`) works here because diameter is always ≥ 0.

**Complexity:** Time O(n), Space O(h)

---

## Comparison

| Approach                | Time  | Space | Notes                                  |
|-------------------------|-------|-------|----------------------------------------|
| DFS + ref param (yours) | O(n)  | O(h)  | Optimal; avoids global state           |
| Naive two-function      | O(n²) | O(h)  | Easy to understand, bad performance    |
| DFS + class member      | O(n)  | O(h)  | Cleaner signature, same logic as yours |

**Approaches 1 and 3 are equivalent** — preference is stylistic. Approach 1 avoids mutable class state, which is slightly safer if the object is reused.

## Notes

- `maxi` is passed by reference so updates propagate up without a global variable.
- For a single-node tree, `left + right = 0`, so `maxi = 0` — correct.
- `INT_MIN` is safe here since the minimum possible diameter is 0, which will always overwrite it.
